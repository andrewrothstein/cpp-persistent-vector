#ifndef _PERSISTENT_VECTOR
#define _PERSISTENT_VECTOR

/**
 *   copy of code from
 *   Copyright (c) Rich Hickey. All rights reserved.
 *   The use and distribution terms for this software are covered by the
 *   Eclipse Public License 1.0 (http://opensource.org/licenses/eclipse-1.0.php)
 *   which can be found in the file epl-v10.html at the root of this distribution.
 *   By using this software in any fashion, you are agreeing to be bound by
 * 	 the terms of this license.
 *   You must not remove this notice, or any other, from this software.
 **/

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

    PersistentVector conj(
        PersistentVector rhs)
    {
        return *this;
    }
    
    PersistentVector(int c, int s, NodePtr r, T * t)
        : cnt(c)
        , shift(sh)
        , root(r)
        , tail(t)
    {}
    
    public Object[] arrayFor(int i){
        if(i >= 0 && i < cnt)
        {
            if(i >= tailoff())
                return tail;
            Node node = root;
            for(int level = shift; level > 0; level -= 5)
                node = (Node) node.array[(i >>> level) & 0x01f];
            return node.array;
        }
        throw new IndexOutOfBoundsException();
    }

    static const Note EMPTY_NODE(new T[32]);

    struct Node
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
