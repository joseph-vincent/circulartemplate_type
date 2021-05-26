#include<iostream>
#include<initializer_list>
using namespace std;

template<class T>
class circular
{
    private :
        int m_capacity = 10;
        int m_begin = 0;
        int m_end = 0;
        bool m_circular = false;
        T *m_values = nullptr;

    public:
        class iterator;
    public:
        circular() //: m_end(0), m_capacity(10), m_values(nullptr);
        {
            this->m_values = new T [m_capacity];
        }
        circular(int capacity) : m_capacity(capacity)
        {
            this->m_values = new T [m_capacity];
        }
        circular(initializer_list<T> elements) 
        {
            m_capacity = elements.size();
            this->m_values = new T [m_capacity];
            for (auto element : elements )
            {
                push_back(element);
            }
        }

        ~circular()
        {
            delete [] this->m_values;
        }


        void push_back(T value) 
        {  
            cout << "Inserting "<< value << endl;
            this->m_values[m_end++] = value;
            if (m_end == m_capacity ) { m_circular = true; m_end = 0; } //reset the next position
            this->m_values[m_end] = T();
            if (m_begin == m_capacity-1 ) { m_begin = 0; } //reset the next position
            else if (m_circular) { m_begin++;}
        }

        auto size() -> decltype(m_capacity)
        {
            if (m_circular) {return m_capacity;}
            else { return (m_end - m_begin); }
        }
        auto at(int pos) -> T& { return m_values[pos];
        }

        auto begin() { return iterator(m_begin,*this);}
        auto end() { return iterator(m_end,*this);}

        void show()
        {
            cout << "=============================="<< this->size() << endl;
            for (int count =0 ; count < m_capacity; count ++ )
            {
                cout << count << " : " << m_values[count];
                if ( count == this->m_begin)
                    cout << "<-- begin";
                if ( count == this->m_end)
                    cout << "<-- end";
                cout << endl;
                
            }
            cout << "==============================" << endl;
        }

};


template<class T>
class circular<T>::iterator
{
    int pos;
    circular &object;

    public:
        iterator(int pos, circular &object): pos(pos), object(object) 
        {}
    public:


        T& operator* () 
        { 
            return object.at(pos);
        }
        void operator++ (int)
        {//  for postfix
            if(this->pos == this->object.size()-1)
                this->pos = 0;
            else
                this->pos++;
        } 
        void operator++ () 
        {//  for prefix
            if(this->pos == this->object.size()-1)
                this->pos = 0;
            else
                this->pos++;
        } 
        bool operator!= (const iterator &other) const
        { 
            return (other.pos != this->pos);
        } 
        void operator= (iterator destination) 
        { 
            destination.pos = this->pos;
            destination.object = this->object;
        } 

};
