#ifndef _PERSISTENT_VECTOR
#define _PERSISTENT_VECTOR

template <class T>
class PersistentVector
{
  public :

  PersistentVector(int c, int s, NodePtr r, T * t)
    : cnt(c)
    , shift(s)
    , root(r)
    , tail(t)
  {}
      
  private :

    static const Note EMPTY_NODE(new T[32]);

    class Node
    {
      public :
	Node(T * a) : d(a) {}
        ~Node() { delete [] d; }
	T * d;
    };

    typedef std::shared_ptr<T> NodePtr;
  
    const int cnt;
    const int shift;
    const NodePtr root;
    const T * tail;
    
};

#endif // _PERSISTENT_VECTOR
