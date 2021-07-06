//
// Created by 김태현 on 2021/07/07.
//

#ifndef SPA_COMPARE_LOCATION_H
#define SPA_COMPARE_LOCATION_H

class Location{
private:
    int xCoord;
    int yCoord;

public:
    void SetXCoord(int);
    int GetXCoord() const;
    void SetYCoord(int);
    int GetYCoord() const;
};

#endif //SPA_COMPARE_LOCATION_H
