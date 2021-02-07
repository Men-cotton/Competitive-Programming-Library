struct pos {
    int x, y;
    pos operator+(const pos &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }
    pos &operator+=(const pos &rhs) {
        x += rhs.x, y += rhs.y;
        return *this;
    }
    bool operator==(pos &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

const vector<pos> moves{{1,  0},
                        {-1, 0},
                        {0,  1},
                        {0,  -1}};

int w, h;

bool inRange(pos p) {
    return 0 <= p.x && p.x < h && 0 <= p.y && p.y < w;
}
