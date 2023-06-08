#ifndef POSITION_H
#define POSITION_H
class Position{
    public:
        Position();
        Position(int x, int y);
        Position(const Position& pos);
        //bool operator==(const Position& pos);
        friend bool operator==(Position a, Position b) {
            return (a.getX() == b.getX() && a.getY() == b.getY());
        }
        Position& operator=(const Position& pos);
        ~Position();
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
    private:
        int x;
        int y;
};
#endif POSITION_H