//
//  DoublyLinkedNode.h
//  Assignment 5
//
//  Created by Reuben Wilson on 21/04/2014.
//  Copyright (c) 2014. All rights reserved.
//

#ifndef __Assignment_5__DoublyLinkedNode__
#define __Assignment_5__DoublyLinkedNode__

template<class DataType>
class DoublyLinkedNode
{
public:
    typedef DoublyLinkedNode<DataType> Node;
    
private:
    DataType fValue;
    Node* fNext;
    Node* fPrevious;
    
    DoublyLinkedNode()
    {
        fValue = DataType();
        fNext = &NIL;
        fPrevious = &NIL;
    }
public:
    static Node NIL;
    DoublyLinkedNode(const DataType& aValue);
    void prepend(Node& aNode);
    void append(Node& aNode);
    void remove();
    const DataType& getValue() const;
    const Node& getNext() const;
    const Node& getPrevious() const;
};

template<class DataType>
DoublyLinkedNode<DataType> DoublyLinkedNode<DataType>::NIL;

template<class DataType>
DoublyLinkedNode<DataType>::DoublyLinkedNode(const DataType& aValue)
{
    fNext = &NIL;
    fPrevious = &NIL;
    fValue = aValue;
}

template<class DataType>
void DoublyLinkedNode<DataType>::prepend(Node& aNode)
{
    aNode.fNext = this;
    if (fPrevious != &NIL)
    {
        aNode.fPrevious = fPrevious;
        fPrevious->fNext = &aNode;
    }
    fPrevious = &aNode;
}

template<class DataType>
void DoublyLinkedNode<DataType>::append(Node& aNode)
{
    aNode.fPrevious = this;
    if (fNext != &NIL)
    {
        aNode.fNext = fNext;
        fNext->fPrevious = &aNode;
    }
    fNext = &aNode;
}

template<class DataType>
void DoublyLinkedNode<DataType>::remove()
{
    if ( fPrevious != &NIL )
    {
        fPrevious->fNext = fNext;
    }
    
    if ( fNext != &NIL )
    {
        fNext->fPrevious = fPrevious;
    }
}

template<class DataType>
const DataType& DoublyLinkedNode<DataType>::getValue() const
{
    return fValue;
}

template<class DataType>
const DoublyLinkedNode<DataType>& DoublyLinkedNode<DataType>::getNext() const
{
    return *fNext;
}

template<class DataType>
const DoublyLinkedNode<DataType>& DoublyLinkedNode<DataType>::getPrevious() const
{
    return *fPrevious;
}

#endif /* defined(__Assignment_5__DoublyLinkedNode__) */
