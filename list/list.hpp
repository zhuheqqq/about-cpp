#include <iostream>
//使用你的名字替换YOUR_NAME
#include<gtest/gtest.h>
namespace zhuheqin
{
    template <class T>
    // list存储的节点
    // 可以根据你的需要添加适当的成员函数与成员变量
    struct node
    {
        node<T> *prev_;
        node<T> *next_;
        T data_;
        //构造函数
        node(const T &data)
            : data_(data), prev_(nullptr), next_(nullptr)
        {
        }
        //默认构造函数
        node()
            : prev_(nullptr), next_(nullptr)
        {
        }
        //析构函数
        ~node()
        {
        }
    };

    template <class T>
    //迭代器类,(类比指针)

    struct iterator
    {
        typedef node<T> node_;
        typedef iterator<T> iterator_;
        node_ *data_;
        iterator(node_ *data)
            : data_(data)
        {
        }
        ~iterator()
        {
        }
        //迭代到下一个节点
        //++it
        iterator_ &operator++()//返回引用,无限的对指针进行引用,连续赋值
        {                      //引用就是为了可以在外面改变他的值（使它从左值变为右值）
                            //左值可以修改因为他是变量，右值不可以修改 
            data_=data_->next_;
            return *this;//返回值为移动后的节点
        }
        //迭代到前一个节点
        //--it
        iterator_ &operator--()
        {
            data_=data_->prev_;
            return *this;
        }
        // it++
        iterator operator++(int)//占位参数,写int编译器自动区分为后置++
        {
            iterator tmp(*this);
            data_=data_->next_;
            return tmp;//返回的是值,不能返回局部对象的引用
        }
        //it--
        iterator operator--(int)
        {
            iterator tmp(*this);
            data_=data_->prev_;
            return tmp;
        }
        //获得迭代器的值
        T &operator*()//返回引用本身
        {
            return data_->data_;//list每个位置存储的是结构体
        }
        //获得迭代器对应的指针
        T *operator->()
        {
            return &data_->data_;
        }
        /*在 C++ 中，当我们声明一个变量时，实际上是在内存中分配了一段存储空间，我们可以将这段存储空间理解为一个盒子，里面存储了我们所声明的变量的值。
        那么当我们用一个变量去引用（取得）这个盒子里的值时，这个变量实际上指向了这个盒子，我们可以将这个变量理解为这个盒子的标签。
        在这种情况下，我们可以通过这个变量对这个盒子里的值进行读取或修改，这就是所谓的引用。
        回到你的问题，T &operator*() 中的 * 操作符是用来获取迭代器所指向的数据（或者称为节点）的引用。
        由于 data_->data_ 表示的是数据本身，返回的就是数据本身的引用。
        因此，通过对迭代器进行解引用操作 *，我们可以直接获取迭代器所指向的数据，并对数据进行操作。
        而 T *operator->() 中的 -> 操作符则是用来获取迭代器所指向的数据（或者称为节点）的指针。
        由于 data_->data_ 表示的是数据本身，我们需要使用取地址符 & 来获取数据的指针，即 &data_->data_，然后返回这个指针。
        因此，通过对迭代器进行箭头操作 ->，我们可以获取迭代器所指向的数据的指针，并进行指针操作。*/

        //重载==
        bool operator==(const iterator_ &t)
        {
            return data_==t.data_;
        }
        //重载！=
        bool operator!=(const iterator_ &t)
        {
            return data_!=t.data_;
        }

        //**可以添加需要的成员变量与成员函数**
    };

    template <class T>
    class list
    {
    public:
        typedef node<T> node_;
        typedef iterator<T> Iterator;

    private:
        //可以添加你需要的成员变量
        node_ *head_; //头节点,哨兵（不存储有效数据）
    public:
        //构造函数
        list()
        {
            head_=new node_;
            head_->next_=head_;
            head_->prev_=head_;
        }
        //拷贝构造，要求实现深拷贝
        list(const list<T> &lt)
        {
            //初始化头节点
            head_=new node_;
            head_->next_=head_;
            head_->prev_=head_;

            for(const auto &e:lt)
            {
                push_back(e);
            }

        }
        template <class inputIterator>
        //迭代器构造
        list(inputIterator begin, inputIterator end)
        {
            head_=new node_;
            head_->next_=head_;
            head_->prev_=head_;

            while(begin!=end)
            {
                push_back(*begin);
                ++begin;
            }
        }

        ~list()
        {
            clear();
            delete head_;
            head_=nullptr;
        }
        //拷贝赋值
        //先将被赋值的对象内容全部清空（保留头结点），然后讲新的节点插入即可。
        list<T> &operator=(const list<T> &lt)
        {
            if(this!=&lt)
            {
                clear();
                for(const auto &e:lt)
                {
                    push_back(e);
                }
            }
            return *this;
        }
        //清空list中的数据
        void clear()
        {
            iterator it=begin();
            while(it!=end())
            {
                iterator tmp=it;
                ++it;
                erase(tmp);
                // erase(it);
                // it=tmp;此时迭代器it已经失效,对其++会产生未定义的行为
            }
        }
        //返回容器中存储的有效节点个数
        size_t size() const
        {
            size_t count = 0;
            for (auto iter = begin(); iter != end(); ++iter) {
                ++count;
            }
            //这里前置++和后置++效果一样但前置++效率更快
            return count;
        }
        //判断是否为空
        bool empty() const
        {
            if(begin()!=end())
            {
                return false;
            }
            return true;
        }
        //尾插
        bool push_back(const T &data)
        {
            return insert(end(),data,false);//这里虽然是向后插入数据,但仔细想一想就知道这里其实参数应该填false,才能达到尾插的效果
        }
        //头插
        bool push_front(const T &data)
        {
            return insert(begin(),data,false);
        }
        //尾删
        bool pop_back()
        {
            return erase(--end());//end指向最后一个有效节点的下一个位置,尾删是删最后一个有效节点
        }
        //头删
        bool pop_front()
        {
            return erase(begin());
        }
        //默认新数据添加到pos迭代器的后面,根据back的方向决定插入在pos的前面还是后面
        bool insert(Iterator pos, const T &data, bool back = true)
        {
            node_*newnode=new node_(data);
            if(back!=true)//插入到pos前面
            {
                node_* cur=pos.data_;
                node_* prev=cur->prev_;

                newnode->prev_=prev;
                prev->next_=newnode;
                cur->prev_=newnode;
                newnode->next_=cur;

                
                return true;

            }else{//插入到pos后面
                node_* cur=pos.data_;
                node_* next=cur->next_;

                newnode->next_=next;
                next->prev_=newnode;
                cur->next_=newnode;
                newnode->prev_=cur;

                
                return true;
            }

            return false;
        }
        //删除pos位置的元素
        bool erase(Iterator pos)
        {
            node_* cur=pos.data_;
            

            cur->prev_->next_=cur->next_;
            cur->next_->prev_=cur->prev_;

            delete cur;
            return true;
        }

        //获得list第一个有效节点的迭代器
        Iterator begin() const
        {
            //1:
            // Iterator it(head_->next_);
            // return it;

            //2:
            return Iterator(head_->next_);
        }

        //获得list最后一个节点的下一个位置，可以理解为nullptr
        Iterator end() const
        {

            //1:
           return Iterator(head_);

           //2:
        //    Iterator it(head_);
        //    return it;
        }
        //查找data对应的迭代器
        Iterator find(const T &data) const
        {
            for(auto it=begin();it!=end();++it)
            {
                if(*it==data)
                {
                    return it;
                }
            }
            return end();
            //or  return nullptr;
        }
        //获得第一个有效节点
        T front() const
        {
            return head_->next_->data_;
        }
        //获得最后一个有效节点
        T back() const
        {
            return head_->prev_->data_;//带头节点的双向循环链表
        }

    private:
        //可以添加你需要的成员函数
    };
};