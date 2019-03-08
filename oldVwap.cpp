#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class VWAP {
private:
  struct TradeTotals {
    double _p; // summation of each trade times its size  ( price * size )
    int _s;    // total trade volume ( summation of all szies ) 
    TradeTotals() : _p(0.0), _s(0){};
  };

  // Running totals , by symbol
  std::unordered_map<int , TradeTotals> _runningTradeTotals;          


public:
  VWAP() {}
  void clear() {
    _runningTradeTotals.clear();
  }

    // Store the running totals to allow us to calulate vwap on demand.
    // Division is expensive and better done on demand rather then as the values
    // change
  void insertTrade(int sym, double price, int size) {

    // Assume that a size of 0 or a trade price of 0.0 is an error
    if (price == 0.0 || size == 0) {
      std::cerr << " Invalid trade for sym: " << sym  << " " << price << " " << size
                << std::endl;
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

  // calculate and return the vwap 
  double getVwap(int sym) 
  {
    double vwap = 0.0;
    std::cout << " total " << _runningTradeTotals[sym]._p << " total trades "
              << _runningTradeTotals[sym]._s << std::endl;

    if (_runningTradeTotals[sym]._s != 0)
      vwap = _runningTradeTotals[sym]._p / (double)_runningTradeTotals[sym]._s;
   std::cout << " vwap " << vwap << std::endl;
    return (vwap);
  }
};

int main(int c, char *vg[]) {
  VWAP v;

  int id = 100;
  v.insertTrade(100 , 10.0, 100);
  v.insertTrade(100 , 15.0, 100);
  v.getVwap(100);
}
