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
            data_=data_->next;
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
            return *(data_).data_;//list每个位置存储的是结构体
        }
        //获得迭代器对应的指针
        T *operator->()
        {
            return this->data_->data_;
        }
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

        //**可以添加需要的成员变量与成员函数*
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
                it=erase(it);
            }
        }
        //返回容器中存储的有效节点个数
        size_t size() const
        {
        }
        //判断是否为空
        bool empty() const
        {
        }
        //尾插
        void push_back(const T &data)
        {
        }
        //头插
        void push_front(const T &data)
        {
        }
        //尾删
        void pop_back()
        {
        }
        //头删
        void pop_front()
        {
        }
        //默认新数据添加到pos迭代器的后面,根据back的方向决定插入在pos的前面还是后面
        void insert(Iterator pos, const T &data, bool back = true)
        {
        }
        //删除pos位置的元素
        void erase(Iterator pos)
        {
        }

        //获得list第一个有效节点的迭代器
        Iterator begin() const
        {
            return Iterator(head_->next);
        }

        //获得list最后一个节点的下一个位置，可以理解为nullptr
        Iterator end() const
        {
            return Iterator(head_);
        }
        //查找data对应的迭代器
        Iterator find(const T &data) const
        {
        }
        //获得第一个有效节点
        node_ front() const
        {
        }
        //获得最后一个有效节点
        node_ back() const
        {
        }

    private:
        //可以添加你需要的成员函数
    };
};