class Position{
    public:
        Position();
        Position(int x, int y);
        ~Position();
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
    private:
        int x;
        int y;
};