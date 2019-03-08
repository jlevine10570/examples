#include <iostream>
class REFBLOCK {
    private:
    int count; // Reference count
    public:
    void AddRef() { count++; }

    int Release()
    {
        // Decrement and return the reference count.
        return --count;
    }
};

template < typename T > class SMARTPTR
{
private:
    T*    pData;       // pointer
    REFBLOCK* reference; // Reference count

public:
    SMARTPTR() : pData(0), reference(0) 
    {
        // Create a new reference 
        reference = new REFBLOCK();
        // Increment the reference count
        reference->AddRef();
    }

    SMARTPTR(T* pValue) : pData(pValue), reference(0)
    {
        // Create a new reference 
        reference = new REFBLOCK();
        // Increment the reference count
        reference->AddRef();
    }

    SMARTPTR(const SMARTPTR<T>& sp) : pData(sp.pData), reference(sp.reference)
    {
        // Copy constructor
        // Copy the data and reference pointer
        // and increment the reference count
        reference->AddRef();
    }

    ~SMARTPTR() // Destructor
    {
        // Decrement the reference count
        // if reference become zero delete the data
        if(reference->Release() == 0)
        {
            delete pData;
            delete reference;
        }
    }

    T& operator* () { std::cout << " Use * \n"; return *pData; }
    T* operator-> () { return pData; }
    
    SMARTPTR<T>& operator = (const SMARTPTR<T>& sp)
    {
        // Assignment operator
        if (this != &sp) // Avoid self assignment
        {
            // Decrement the old reference count
            // if reference become zero delete the old data
            if(reference->Release() == 0)
            {
                delete pData;
                delete reference;
            }

            // Copy the data and reference pointer
            // and increment the reference count
            pData = sp.pData;
            reference = sp.reference;
            reference->AddRef();
        }
        return *this;
    } };

int main()
{
	struct ZZ{ int x; int y;};
SMARTPTR <ZZ> foo(new ZZ);
(*foo).x=9;
foo->x=9;
}
