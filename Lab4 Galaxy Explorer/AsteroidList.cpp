#include <galaxy-explorer/AsteroidList.hpp>


//Default Constructor for each node
AsteroidListItem::AsteroidListItem() {
	this->next = nullptr;
	this->data = nullptr;
}

//Overloaded Constructor for each node
AsteroidListItem::AsteroidListItem(Asteroid a) {
	this->next = nullptr;
	this->data = new Asteroid(a.getID(), a.getMass(), a.getHealth(), a.getCurrentHitbox(), a.getVelocity());
}

//Default Destructor for each node
AsteroidListItem::~AsteroidListItem() {
}

//Default Constructor for list
AsteroidList::AsteroidList()
{
}

//Copy Constructor for list
AsteroidList::AsteroidList(const AsteroidList& src)
{
	// The functions in this class are listed in a suggested order of implementation,
	// except for this one and the destructor (because you should put all your constructors together).
    
    const AsteroidListItem* temp = src.begin();
    AsteroidListItem* aptr = this->beforeBegin(); // Creating head for new list
    while(temp != NULL){
        AsteroidListItem* newAsteroid = new AsteroidListItem(temp->getData());
        aptr->setNext(newAsteroid);
        aptr = aptr->getNext();
        temp = temp->getNext();
    }
}

//Default Destructor for list
AsteroidList::~AsteroidList() {
	// The functions in this class are listed in a suggested order of implementation,
	// except for this one and the copy constructor (because you should put all your constructors together).
    clear();
}

//Inserting at the front of list
void AsteroidList::pushFront(Asteroid e) {
    AsteroidListItem* newAsteroid = new AsteroidListItem(e);
    AsteroidListItem* temp = head.getNext();
    head.setNext(newAsteroid);
    newAsteroid->setNext(temp);
}

//Returning Reference to head of list
Asteroid& AsteroidList::front() {
    if(head.hasNext()){
        return (head.getNext()->getData());
    }
    else 
        return head.getData();
}

//Returns a constant reference to head of list
const Asteroid& AsteroidList::front() const {
	if(head.hasNext()){
        return (head.getNext()->getData());
    }
    else 
        return head.getData();
}

//Checks if list is empty
bool AsteroidList::isEmpty() const {
    if(begin() == nullptr && end() == nullptr){
        return true;
    }
    else 
	return false;
}

//Returns number of items in list
int AsteroidList::size() const {
    if(head.hasNext()){
        int count = 0;
        const AsteroidListItem* temp = head.getNext();
        while(temp != NULL){
            count++;
            temp = temp->getNext();
        }
        return count;
    }
    else
	return 0;
}

//Returns pointer to head
AsteroidListItem* AsteroidList::beforeBegin() {
	return &(this->head);
}

//Returns constant pointer to head
const AsteroidListItem* AsteroidList::beforeBegin() const {
	return &(this->head);
}

//Returns pointer to first item in list
AsteroidListItem* AsteroidList::begin() {
        return (this->head).getNext();
}

//Returns constant pointer to first item in list
const AsteroidListItem* AsteroidList::begin() const {
	return (this->head).getNext();
}

//Returns pointer to last item in list
AsteroidListItem* AsteroidList::beforeEnd() {
    if(head.hasNext()){
        AsteroidListItem* temp = head.getNext();
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }
        return temp;
    }
    else
	return &head;
}

//Returns constant pointer to the last item in list
const AsteroidListItem* AsteroidList::beforeEnd() const {
    if(head.hasNext()){
        const AsteroidListItem* temp = head.getNext();
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }
        return temp;
    }
    else {
        const AsteroidListItem* temp = &head;
        return temp;
    }
}

//Returns pointer to after the last item of list
AsteroidListItem* AsteroidList::end() {
	return nullptr;
}

//Returns constant pointer to after the last item of list
const AsteroidListItem* AsteroidList::end() const {
	return nullptr;
}

//Adds new item to list after 'prev'
AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, Asteroid e) {
    AsteroidListItem* newAsteroid = new AsteroidListItem(e);
    if(prev == nullptr){
        return nullptr;
    }
    else { 
        AsteroidListItem* temp = prev->getNext();
        prev->setNext(newAsteroid);
        newAsteroid->setNext(temp);
        return newAsteroid;
    }
}

//Adds new items to the list after 'prev' maintaining order 
AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, const AsteroidList& others) {
    if (others.beforeBegin() == others.beforeEnd() || prev == NULL){
        return prev;
    }
    else {
        const AsteroidListItem* temp = others.beforeBegin();
        while (temp->hasNext()){
            temp = temp->getNext();
            prev = insertAfter(prev, temp->getData());
        }
        return prev;
    }
}


//Deletes the item after 'prev'
AsteroidListItem* AsteroidList::eraseAfter(AsteroidListItem* prev) {
    AsteroidListItem* temp;
    if(prev->hasNext()){
        temp = prev->getNext()->getNext();
        delete prev->getNext();
        prev->setNext(temp);
    }
    return temp;
}

//Deletes all items of list
void AsteroidList::clear() {
    AsteroidListItem* temp = head.getNext();
    AsteroidListItem* del;
    while (temp != NULL){
        del = temp;
        temp = temp->getNext();
        delete del;
        head.setNext(temp);
    }
}

//Overloaded Operator '='
AsteroidList& AsteroidList::operator=(const AsteroidList& src) {
    if (this == &src){
        return *this;
    }
    else {
        this->clear();
        this->insertAfter(this->beforeBegin(), src);
        return *this;
    }
}


