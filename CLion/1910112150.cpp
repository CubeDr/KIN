//
// Created by HyunI on 2019-10-11.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include <vector>

class Point {
private:
    int *coords;
public:
    Point(int dimension) {
        coords = new int[dimension];
    }

    ~Point() {
        delete[] coords;
    }

    int get(int dim) const {
        return coords[dim];
    }

    void set(int dim, int value) {
        coords[dim] = value;
    }
};

using namespace std;

int main()
{
    ifstream fin;

    fin.open("test.txt");
    if (!fin) {
        cout << "파일을 읽을 수 가 없습니다." << endl;
        exit(1);
    }

    vector<Point*> points;
    // 3차원 좌표를 읽어 Point 추가
    int coords[3];
    while(!fin.eof()) {
        for(int i=0; i<3; i++)
            fin >> coords[i];

        Point* p = new Point(3);
        for(int i=0; i<3; i++)
            p->set(i, coords[i]);

        points.push_back(p);
    }
    fin.close();

    for(const Point* p: points) {
        for(int i=0; i<3; i++)
            cout << p->get(i) << " ";
        cout << endl;
    }

    for(const Point* p: points)
        delete p;
    points.clear();

    return 0;
}