
template <class K>

class LinkedList {
    public:
        LinkedList();
        void add(K);
        K remove();

    private:
        K dummy;
        K* p;
}
