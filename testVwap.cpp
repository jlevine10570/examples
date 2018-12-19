#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


struct Trade {
  int stock_id;
  double price;
  unsigned int volume;
};
struct TradeTotals {
  double _p; // summation of each trade times its size  ( price * size )
  int _s;    // total trade volume ( summation of all szies )
  TradeTotals() : _p(0.0), _s(0){};
};

class TradeListener {
private:
  // Running totals , by symbol.  We do not need ordered data so use the faster
  // unordered map
  std::unordered_map<int, TradeTotals> _runningTradeTotals;
  //
  // Store the running totals to allow us to calulate vwap on demand.
  // Division is expensive and better done on demand rather then as the values
  // change
  void insertTrade(int sym, double price, int size) {

    // Assume that a size of 0 or a trade price of 0.0 is an error
    if (price == 0.0 || size == 0) {
      std::cerr << " Invalid trade for sym: " << sym << " " << price << " "
                << size << std::endl;
      return;
    }

    // assume a negative price or size indicates a cancel or correction
    if (price < 0.0 || size < 0) {
       correctTradeTotals( sym, price, size);
      return;
    }

    _runningTradeTotals[sym]._p += size * price;
    _runningTradeTotals[sym]._s += size;
  }
  double getVwap(int stock_id) const {
    double vwap = 0.0;
    try {
      const auto &totals = _runningTradeTotals.at(stock_id);
      if (totals._s != 0)
        vwap = totals._p / (double)totals._s;
    } catch (...) {
      std::cerr << "No vwap found for sym id : " << stock_id << '\n';
    }

    return (vwap);
  }
  // apply the correction to the data.
  // if the paaplication of the correction will create a bad state 
  // write a message and undo the correction 
  void correctTradeTotals(int sym, double price, int size) 
  {
    auto p = _runningTradeTotals[sym]._p;
    auto s = _runningTradeTotals[sym]._s;
    std::cerr << "Found cancel/correction for sym : " << sym << '\n';
    _runningTradeTotals[sym]._p -= std::abs(size * price);
    _runningTradeTotals[sym]._s -= std::abs(size);

    if (_runningTradeTotals[sym]._s < 0 || _runningTradeTotals[sym]._p < 0.0) {
      std::cerr << "Ignore cancel/correction " ;
      std::cerr << " it would created an invalid for sym " << sym << '\n';
    _runningTradeTotals[sym]._p =p;
    _runningTradeTotals[sym]._s =s;
    }
  }


public:
  /*
   * Handler called when each trade arrives.
   */
  void on_trade(const Trade &t) { insertTrade(t.stock_id, t.price, t.volume); }
  /*
   * Weighted average price of the trades seen so far in stock_id,
   * weighted by volume of each trade.
   */
  double get_vwap(int stock_id) const { return getVwap(stock_id); }
};
#if 0 
int main(int c, char *vg[]) {

TradeListener tl;
Trade t;
t.stock_id=100;
t.volume=100;
t.price=10;
tl.on_trade(t);
t.price=15;
tl.on_trade(t);
std::cout << tl.get_vwap(100) << '\n';
std::cout << tl.get_vwap(10) << '\n';
t.stock_id=100;
t.price=-15;
tl.on_trade(t);
std::cout << tl.get_vwap(100) << '\n';
}
#endif
