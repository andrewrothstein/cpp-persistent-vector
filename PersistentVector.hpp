#ifndef _PERSISTENT_VECTOR
#define _PERSISTENT_VECTOR

template <class T>
class PersistentVector
{
  public :

  private :

    static const Note EMPTY_NODE(new T[32]);

    class Node
    {
      public :
	Node(T [] a) : d(a) {}
	T [] d;
    };

    const int cnt;
    const int shift;
    const Node root;
    
};

#endif // _PERSISTENT_VECTOR
