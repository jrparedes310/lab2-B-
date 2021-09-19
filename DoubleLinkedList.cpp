#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__
#include <iostream>
template <class T>
class DoubleNode{
    private:
    T value;
    DoubleNode<T>* next;
    DoubleNode<T>* prev;
    public:
    DoubleNode(T value=0,DoubleNode *next=nullptr, DoubleNode<T> *prev=nullptr) : value(value),next(next),prev(prev){}
    T getValue() const{
        return value;
    }
    void setValue(T value){
        this->value = value;
    }

    DoubleNode<T>* getNext() const{
        return next;
    }

    void setNext(DoubleNode<T>* next){
        this->next = next;
    }
    DoubleNode<T>* getPrev() const{
        return prev;
    }

    void setPrev(DoubleNode<T>* prev){
        this->prev = prev;
    }
};


template <class T>
class DoubleLinkedList{
    private:
        DoubleNode<T>* head;
        DoubleNode<T>* pActual;
        int size;
    public:
        // 
        DoubleLinkedList(DoubleNode<T> *head=nullptr,int size=0):head(head),size(size){}
        int getSize() {return size;}

    DoubleNode<T>* getHead(){ return head; }
    
    void push_back(T value){
        DoubleNode<T> *newDoubleNode=new DoubleNode<T>(value);
        if(head==nullptr){
            head=newDoubleNode;
        }else{
            DoubleNode<T> *tmp=head;
            while(tmp->getNext()!=nullptr){
                tmp=tmp->getNext();
            }
            tmp->setNext(newDoubleNode);
            newDoubleNode->setPrev(tmp);
            //std::cout<<newDoubleNode->getPrev();
        }
        size++;
    }

    
    //este insert no se i funciona cuando trabajo com push_back
    void insert(T value,int index){
        if(index<0){
            if(abs(index)>size){
                std::cout<<"Fuera de rango"<<std::endl;
            }else{
                insert(value,index+size);
            }
        }else{
            if(index>size){
                index=size;
            }
            if(index==0){
                if(size==0){
                    DoubleNode<T> *newDoubleNode=new DoubleNode<T>(value);
                    head=newDoubleNode;
                }else{
                    DoubleNode<T> *newDoubleNode=new DoubleNode<T>(value);
                    DoubleNode<T> *tmp=head;
                    tmp=tmp->getNext();
                    tmp->setPrev(newDoubleNode);
                    newDoubleNode->setNext(head);
                    head=newDoubleNode;
                }
                size++;
            }else if(index==size){
                push_back(value);
            }else{
                DoubleNode<T> *newDoubleNode=new DoubleNode<T>(value);
                DoubleNode<T> *tmp1=head;
                DoubleNode<T> *tmp2=head->getNext();
                for(int i=0;i<index-1;i++){
                    tmp1=tmp1->getNext();
                    tmp2=tmp2->getNext();
                }
                //aqui podrias cread  el new DoubleNode  enlugar de arriba
                newDoubleNode->setNext(tmp1->getNext());
                newDoubleNode->setPrev(tmp1);
            
                tmp2->setPrev(newDoubleNode);
                tmp1->setNext(newDoubleNode);
            
                size++;
            }
        }
    }

    bool look_for(T value){
        DoubleNode<T> *tmp=head;
        while(tmp!=nullptr){
            if(tmp->getValue()==value){
                return true;
            }
        }
        return false;
    }

    void delete_by_value(T value){
        DoubleNode<T> *tmp1=head;
        DoubleNode<T> *tmp2=head->getNext();
        if(tmp1->getValue()==value){
            head=head->getNext();
            tmp2->setPrev(nullptr);
            //delete tmp1;
        }else{
            while(tmp2!=nullptr){
                if(tmp2->getValue()==value){
                    tmp1->setNext(tmp2->getNext());
                    if(tmp2->getNext()!=nullptr){
                        tmp2=tmp2->getNext();
                        tmp2->setPrev(tmp1);
                    }else{
                        delete tmp2;
                    }
                }
                tmp1=tmp1->getNext();
                tmp2=tmp2->getNext();
            }
        }
    }

    void pop(){
        if(head==nullptr){
            std::cout<<"No se puede eliminar";
        }else{
            if(size==1){
                //para probar
                //delete head;
                head=nullptr;
            }else{
                DoubleNode<T> *tmp1=head;
                DoubleNode<T> *tmp2=head->getNext();
                while(tmp2->getNext()!=nullptr){
                    tmp1=tmp1->getNext();
                    tmp2=tmp2->getNext();
                }
                tmp1->setNext(nullptr);
                delete tmp2;
            }
            size--;
            
        }
    }

    void delete_by_position(int index){
        if(index<0){
            if(abs(index)>size){
                std::cout<<"Fuera de rango"<<std::endl;
            }else{
                delete_by_position(index+size);
            }
        }else{
            if(index>=size){
                std::cout<<"Fuera de rango"<<std::endl;
            }else{
                if(index==0){
                    head=head->getNext();
                }else if(index==size-1){
                    pop();
                }else{
                    DoubleNode<T> *tmp1=head;
                    DoubleNode<T> *tmp2=head->getNext();
                    for(int i=0;i<index-1;i++){
                        tmp1=tmp1->getNext();
                        tmp2=tmp2->getNext();
                    }
                    tmp1->setNext(tmp2->getNext());
                    tmp2=tmp2->getNext();
                    tmp2->setPrev(tmp1);
                    size--;
                }
            }
        }
    }
    
    void print(){
        DoubleNode<T> *tmp=head;
        while(tmp!=nullptr){
            //std::cout<<tmp->getValue()<<"("<<tmp<<")"<<"("<<tmp->getNext()<<")"<<"("<<tmp->getPrev()<<")"<<"<->";
            std::cout<<tmp->getValue()<<"<->";
            tmp=tmp->getNext();
        }
        std::cout<<std::endl;
    }
    

    T maximo_iterative(){
        T max=head->getValue();
        DoubleNode<T> *tmp=head;
        for(int i=0;i<size;i++){
            if(max<tmp->getValue()){
                max=tmp->getValue();
            }
            tmp=tmp->getNext();
        }
        return max;
    }


    T maximo_recursive(T max, DoubleNode<T> *tmp){
        if(tmp==nullptr){
            return max;
        }else{
            if(tmp->getValue()>max){
                max=tmp->getValue();
            }
            tmp=tmp->getNext();
            return maximo_recursive(max,tmp);
        }
        
    }

    void recursive_print_begin_end(DoubleNode<T> *tmp){
        if(tmp==nullptr){
            std::cout<<std::endl;
        }else{
            //std::cout<<tmp->getValue()<<"("<<tmp<<")("<<tmp2<<")"<<"<->";
            std::cout<<tmp->getValue()<<"<->";
            tmp=tmp->getNext();
            return recursive_print_begin_end(tmp);
        }
    }
    void recursive_print_end_begin(DoubleNode<T> *tmp){
        if(tmp==nullptr){
            std::cout<<std::endl;
        }else{
            std::cout<<tmp->getValue()<<"<->";
            tmp=tmp->getPrev();
            return recursive_print_end_begin(tmp);
        }
    }

    void iterative_print_end_begin(){
        DoubleNode<T> *tmp=head;
        for(int i=0;i<size-1;i++){
            tmp=tmp->getNext();
        }
        for(int i=0;i<size;i++){
            std::cout<<tmp->getValue()<<"<->";
            tmp=tmp->getPrev();
        }
    }
    int count_even_numbers(){
        DoubleNode<T> *tmp=head;
        int con=0;
        for(int i=0;i<size;i++){
            if((tmp->getValue())%2==0){
                con++;
            }
            tmp=tmp->getNext();
        }
        return con;
    }

    T at(int index){
        DoubleNode<T> *tmp=head;
        for(int i=0;i<index;i++){
            tmp=tmp->getNext();
        }
        return tmp->getValue();
    }

    void swap(int a, int b){
        DoubleNode<T> *tmp1=head;
        for(int i=0;i<a;i++){
            tmp1=tmp1->getNext();
        }
        DoubleNode<T> *tmp2=head;
        for(int i=0;i<b;i++){
            tmp2=tmp2->getNext();
        }
        T value=tmp2->getValue();
        tmp2->setValue(tmp1->getValue());
        tmp1->setValue(value);

    }

    int partition_ascendent(int low,int high){
        T pivot=at(high);
        int i=(low-1);

        for(int j=low;j<=high-1;j++){
            if(at(j)<=pivot){
                i++;
                swap(i,j);
            }
        }
        swap(i+1,high);
        return i+1;        
    }
    int partition_descendent(int low,int high){
        T pivot=at(high);
        int i=(low-1);

        for(int j=low;j<=high-1;j++){
            if(at(j)>=pivot){
                i++;
                swap(i,j);
            }
        }
        swap(i+1,high);
        return i+1;        
    }

    void sort_ascendent(int low, int high){
        if(low<high){
            int pivot=partition_ascendent(low,high);
            sort_ascendent(low,pivot-1);
            sort_ascendent(pivot+1,high);
        }
    }

    void sort_descendent(int low, int high){
        if(low<high){
            int pivot=partition_descendent(low,high);
            sort_descendent(low,pivot-1);
            sort_descendent(pivot+1,high);
        }
    }

    void Begin(){
        pActual=head;
    }
    void Last(){
        while(pActual->getNext()!=nullptr){
            pActual=pActual->getNext();
        }
    }
    void Next(){
        pActual=pActual->getNext();
    }
    void Previous(){
        pActual=pActual->getPrev();
    }

    T getDato(){
        return pActual->getValue();
    }

    void print_data_15(){//ejercicio 15
        Begin();
        for(int i=0;i<size-1;i++){
            std::cout<<getDato()<<"<->";
            Next();
        }
    }
    void print_data_16(){//ejercicio 16
        Last();
        for(int i=0;i<size-1;i++){
            std::cout<<getDato()<<"<->";
            Previous();
        }
    }




};




#endif /* __DOUBLELINKEDLIST_H__ */
