#include "doublylinkedlist.h"

template <typename T>
doublyLinkedList<T>::doublyLinkedList()
{
}

template <typename T>
doublyLinkedList<T>::~doublyLinkedList()
{
}

template <typename T>
void doublyLinkedList<T>::insertDistanceNodeFirst(QString startingCollege, std::vector<QString> endingCollege, std::vector<unsigned int> distance)
{
    distanceNode *temp = new distanceNode;
    temp->startingCollege = startingCollege;
    temp->endingCollege = endingCollege;
    temp->distance = distance;

    if (distanceHead != nullptr)
    {
        temp->next = distanceHead;
        temp->prev = nullptr;
        distanceHead->prev = temp;
        distanceHead = temp;
    }

    // If there is nothing inside linked list
    else if (distanceHead == nullptr)
    {
        distanceHead = temp;
        temp->prev = nullptr;
        temp->next = nullptr;
        distanceTail = temp;
    }
}

template <typename T>
void doublyLinkedList<T>::insertSouvenirNodeFirst(QString collegeName, std::vector<QString> souvenirName, std::vector<double> souvenirPricing)
{
    souvenirNode *temp = new souvenirNode;
    temp->collegeName = collegeName;
    temp->souvenirName = souvenirName;
    temp->souvenirPricing = souvenirPricing;

    if (souvenirHead != nullptr)
    {
        temp->next = distanceHead;
        temp->prev = nullptr;
        souvenirHead->prev = temp;
        souvenirHead = temp;
    }

    // If there is nothing inside linked list
    else if (souvenirHead == nullptr)
    {
        distanceHead = temp;
        temp->prev = temp->next = nullptr;
        souvenirTail = temp;
    }
}

template <typename T>
void doublyLinkedList<T>::deleteDistanceNodeFirst()
{
    if (distanceHead == nullptr)
        exit(1);

    distanceNode *temp = distanceHead;

    if (distanceHead != distanceTail)
    {
        distanceHead = distanceHead->next;
        distanceHead->prev = nullptr;
        delete temp;
        temp = nullptr;
    }

    else if (distanceHead == distanceTail)
    {
        distanceHead = distanceTail = nullptr;
        delete temp;
        temp = nullptr;
    }
}

template <typename T>
void doublyLinkedList<T>::deleteSouvenirNodeFirst()
{
    if (souvenirHead == nullptr)
        exit(1);

    souvenirNode *temp = souvenirHead;

    if (souvenirHead != souvenirTail)
    {
        souvenirHead = souvenirHead->next;
        souvenirHead->prev = nullptr;
        delete temp;
        temp = nullptr;
    }

    else if (souvenirHead == souvenirTail)
    {
        souvenirHead = souvenirTail = nullptr;
        delete temp;
        temp = nullptr;
    }
}

template <typename T>
void doublyLinkedList<T>::insertDistanceNodeLast(QString startingCollege, std::vector<QString> endingCollege, std::vector<unsigned int> distance)
{
    distanceNode *temp = new distanceNode;
    temp->startingCollege = startingCollege;
    temp->endingCollege = endingCollege;
    temp->distance = distance;

    if (distanceHead != nullptr)
    {
        temp->prev = distanceTail;
        distanceTail->next = temp;
        temp->next = nullptr;
        distanceTail = temp;
    }

    // If there is nothing inside linked list
    else if (distanceHead == nullptr)
    {
        distanceHead = temp;
        temp->prev = temp->next = nullptr;
        distanceTail = temp;
    }
}

template <typename T>
void doublyLinkedList<T>::insertSouvenirNodeLast(QString collegeName, std::vector<QString> souvenirName, std::vector<double> souvenirPricing)
{
    souvenirNode *temp = new souvenirNode;
    temp->collegeName = collegeName;
    temp->souvenirName = souvenirName;
    temp->souvenirPricing = souvenirPricing;

    if (souvenirHead != nullptr)
    {
        temp->prev = souvenirTail;
        souvenirTail->next = temp;
        temp->next = nullptr;
        souvenirTail = temp;
    }

    // If there is nothing inside linked list
    else if (souvenirHead == nullptr)
    {
        souvenirHead = temp;
        temp->prev = temp->next = nullptr;
        souvenirTail = temp;
    }
}

template <typename T>
void doublyLinkedList<T>::deleteDistanceNodeLast()
{
    if (distanceHead == nullptr)
        exit(1);

    distanceNode *temp = distanceTail;

    if (distanceHead != distanceTail)
    {
        distanceTail = distanceTail->prev;
        distanceTail->next = nullptr;
        delete temp;
        temp = nullptr;
    }

    else if (distanceHead == distanceTail)
    {
        distanceHead = distanceTail = nullptr;
        delete temp;
        temp = nullptr;
    }
}

template <typename T>
void doublyLinkedList<T>::deleteSouvenirNodeLast()
{
    if (souvenirHead == nullptr)
        exit(1);

    souvenirNode *temp = souvenirTail;

    if (souvenirHead != souvenirTail)
    {
        souvenirTail = souvenirTail->prev;
        souvenirTail->next = nullptr;
        delete temp;
        temp = nullptr;
    }

    else if (souvenirHead == souvenirTail)
    {
        souvenirHead = souvenirTail = nullptr;
        delete temp;
        temp = nullptr;
    }
}

template <typename T>
void doublyLinkedList<T>::printDistanceNode()
{
    distanceNode *temp = distanceHead;
    int i = 0;

    while (temp != nullptr)
    {
        // Parallel vectors so we only need to check one vector
        if(temp->endingCollege[i].isEmpty())
            i = 0;

        // TODO: Make this display on the GUI
        // Use console for now to check if data works
        qDebug() << "Distance from " << temp->startingCollege
                 << " and " << temp->endingCollege[i]
                 << " is " << temp->distance[i];
        ++i;
    }
}

template <typename T>
void doublyLinkedList<T>::printSouvenirNode()
{
    souvenirNode *temp = souvenirHead;

    // O(n^2) for now
    // Maybe try and reduce to O(n) or O(nlogn)
    while (temp != nullptr)
    {
        // TODO: Make this display on the GUI
        // Use console for now to check if data works
        qDebug() << "College: " << temp->collegeName;
        for(int i = 0; i < temp->souvenirName.size(); ++i)
        {
            qDebug() << "Traditional Souvenir & Price: "
                     << temp->souvenirName[i] << " " << temp->souvenirPricing[i];
        }
    }
}

template <typename T>
doublyLinkedList<T> *doublyLinkedList<T>::getDistanceHead()
{ return distanceHead; }

template <typename T>
doublyLinkedList<T> *doublyLinkedList<T>::getSouvenirHead()
{ return souvenirHead; }

template <typename T>
doublyLinkedList<T> *doublyLinkedList<T>::getDistanceTail()
{ return distanceTail; }

template <typename T>
doublyLinkedList<T> *doublyLinkedList<T>::getSouvenirTail()
{ return souvenirTail; }

template <typename T>
linkedListIterator<T> doublyLinkedList<T>::begin(T tempNode)
{
    //! THIS HAS TO BE EITHER distanceHead OR souvenirHead!!!
    linkedListIterator<T> temp(tempNode);
    return temp;
}

template <typename T>
linkedListIterator<T> doublyLinkedList<T>::end(T tempNode)
{
    linkedListIterator<T> temp(nullptr);
    return temp;
}

