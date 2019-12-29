struct pos {
    int x, y;
};

const vector<pos> moves{{1,  0},
                        {-1, 0},
                        {0,  1},
                        {0,  -1}};

bool inRange(pos p) {
    return 0 <= p.x && p.x < h && 0 <= p.y && p.y < w;
}
