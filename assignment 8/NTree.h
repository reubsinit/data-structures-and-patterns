//
//  NTree.h
//  Assignment 8
//
//  Created by Reuben Wilson on 23/05/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_8__NTree__
#define __Assignment_8__NTree__

#include <iostream>

#include <stdexcept>

#include "TreeVisitor.h"
#include "DynamicQueue.h"

template<class T, int N>
class NTree
{
private:
    const T* fKey;
    NTree<T,N>* fNodes[N];
    
    NTree();
    
public:
    static NTree<T,N> NIL;
    
    NTree( const T& aKey );
    
    // copy control
    NTree( const NTree<T,N>& aOtherNTree );
    NTree& operator=( const NTree<T,N>& aOtherNTree );
    ~NTree();
    
    bool isEmpty() const;
    const T& key() const;
    
    NTree& operator[]( unsigned int aIndex ) const;
    
    void attachNTree( unsigned int aIndex, NTree<T,N>* aNTree );
    NTree* detachNTree( unsigned int aIndex );
    
    // tree traversal
    void doDepthFirstTraversal( const TreeVisitor<T>& aVisitor ) const;
    void doBreadthFirstTraversal( const TreeVisitor<T>& aVisitor ) const;
};

template<class T, int N>
NTree<T,N> NTree<T,N>::NIL;

template<class T, int N>
NTree<T,N>::NTree(): fKey((T*)0)
{
    for (int i = 0; i < N; i++)
    {
        fNodes[i] = &NIL;
    }
}

template<class T, int N>
NTree<T,N>::NTree(const T& aKey) : fKey(&aKey)
{
    for (int i = 0; i < N; i++)
    {
        fNodes[i] = &NIL;
    }
}

template<class T, int N>
NTree<T,N>::NTree(const NTree<T,N>& aOtherNTree) : fKey(aOtherNTree.fKey)
{
    for (int i = 0; i < N; i++)
    {
        if (aOtherNTree.fNodes[i] != &NIL)
        {
            fNodes[i] = new NTree<T,N>(*aOtherNTree.fNodes[i]);
        }
        else
        {
            fNodes[i] = &NIL;
        }
    }
}

template<class T, int N>
NTree<T,N>& NTree<T,N>::operator=(const NTree<T, N> &aOtherNTree)
{
    if (this != &aOtherNTree)
    {
        fKey = aOtherNTree.fKey;
        for (int i = 0; i < N; i++)
        {
            if (fNodes[i] != &NIL)
            {
                delete fNodes[i];
            }
            if (aOtherNTree.fNodes[i] != &NIL)
            {
                fNodes[i] = new NTree<T,N>(*aOtherNTree.fNodes[i]);
            }
            else
            {
                fNodes[i] = &NIL;
            }
        }
    }
}

template<class T, int N>
NTree<T,N>::~NTree()
{
    for (int i = 0; i < N; i++)
    {
        if (fNodes[i] != &NIL)
        {
            delete fNodes[i];
        }
    }
}

template<class T, int N>
bool NTree<T,N>::isEmpty() const
{
    return this == &NIL;
}

template<class T, int N>
const T& NTree<T,N>::key() const
{
    return *fKey;
}

template<class T, int N>
NTree<T,N>& NTree<T,N>::operator[](unsigned int aIndex) const
{
    if (isEmpty())
    {
        throw std::domain_error("Empty NTree!");
    }
    if (aIndex < N)
    {
        return *fNodes[aIndex];
    }
    else
    {
        throw std::range_error( "Index out of bounds." );
    }
}

template<class T, int N>
void NTree<T,N>::attachNTree(unsigned int aIndex, NTree<T, N> *aNTree)
{
    if (isEmpty())
    {
        throw std::domain_error("Empty NTree!");
    }
    if (aIndex < N)
    {
        if (fNodes[aIndex] != &NIL)
        {
            throw std::domain_error("Non-empty subtree present!");
        }
        else
        {
            fNodes[aIndex] = aNTree;
        }
    }
    else
    {
        throw std::out_of_range("Illegal subtree index, brah!");
    }
}

template<class T, int N>
NTree<T,N>* NTree<T,N>::detachNTree(unsigned int aIndex)
{
    if (isEmpty())
    {
        throw std::domain_error("Empty NTree!");
    }
    if (aIndex < N)
    {
        NTree<T,N>* lResult = fNodes[aIndex];
        fNodes[aIndex] = &NIL;
        return lResult;
    }
    else
    {
        throw std::out_of_range("Illegal subtree index, brah!");
    }
}

template<class T, int N>
void NTree<T,N>::doDepthFirstTraversal(const TreeVisitor<T>& aVisitor) const
{
    DynamicQueue<const NTree<T,N>*> lQueue;
    if (!isEmpty())
    {
        lQueue.enqueue(this);
    }
    if (!lQueue.isEmpty())
    {
        const NTree<T,N>& lHead = *lQueue.dequeue();
        if (!lHead.isEmpty())
        {
            if (typeid(aVisitor) == typeid(PreOrderVisitor<T>))
            {
                aVisitor.preVisit(lHead.key());
            }
            for (int i = 0; i < N; i++)
            {
                lHead[i].doDepthFirstTraversal(aVisitor);
            }
            if (typeid(aVisitor) == typeid(PostOrderVisitor<T>))
            {
                aVisitor.postVisit(lHead.key());
            }
        }
    }
}

template<class T, int N>
void NTree<T,N>::doBreadthFirstTraversal(const TreeVisitor<T>& aVisitor) const
{
    DynamicQueue<const NTree<T,N>*> lQueue;
    if (!isEmpty())
    {
        lQueue.enqueue(this);
    }
    while (!lQueue.isEmpty())
    {
        const NTree<T,N>& lHead = *lQueue.dequeue();
        if (!lHead.isEmpty())
        {
            aVisitor.visit(lHead.key());
        }
        for (int i = 0; i < N; i++)
        {
            if (!lHead[i].isEmpty())
            {
                lQueue.enqueue(&lHead[i]);
            }
        }
    }
}
#endif /* defined(__Assignment_8__NTree__) */
