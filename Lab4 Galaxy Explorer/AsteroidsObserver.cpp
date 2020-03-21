/*
 * This file was developed for the Fall 2018 instance of ECE244 at the University of Toronto.
 * Creator: Matthew J. P. Walker
 */


#include <galaxy-explorer/AsteroidsObserver.hpp>

void AsteroidsObserver::onAsteroidInRange(Asteroid asteroid) {
    asteroid_list.pushFront(asteroid);
}

void AsteroidsObserver::onAsteroidUpdate(Asteroid asteroid) {
    AsteroidListItem * temp =  asteroid_list.beforeBegin(); //points to head
    if(temp->getNext() == NULL)
        return;
    while(temp->getNext()->getData().getID() != asteroid.getID()) //find the previous node
    {
       temp = temp->getNext();   
    }
    AsteroidListItem * ptr = new AsteroidListItem(asteroid); //new list item
    AsteroidListItem *next = asteroid_list.eraseAfter(temp); //points to node after deleting the specified node
    temp->setNext(ptr); //temp points to new item
    ptr->setNext(next); //new item completes the chain
}

void AsteroidsObserver::onAsteroidOutOfRange(Asteroid asteroid) {
    
    AsteroidListItem * temp =  asteroid_list.beforeBegin();
    if(temp->getNext() == NULL)
        return;
    while(temp->getNext()->getData().getID() != asteroid.getID())
    {
       temp = temp->getNext();   
    }
    asteroid_list.eraseAfter(temp);
}

void AsteroidsObserver::onAsteroidDestroy(Asteroid asteroid) {
    AsteroidListItem * temp =  asteroid_list.beforeBegin();
    while(temp->getNext()->getData().getID() != asteroid.getID())
    {
       temp = temp->getNext();   
    }
    asteroid_list.eraseAfter(temp);
}
