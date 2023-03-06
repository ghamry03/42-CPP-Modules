# include "bsp.hpp"

bool    bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed w1, w2;

    // Calculatiog the first vector
    {
        Fixed Ax = a.getX();
        Fixed Ay = a.getY();
        Fixed Bx = b.getX();
        Fixed By = b.getY();
        Fixed Cx = c.getX();
        Fixed Cy = c.getY();
        Fixed Px = point.getX();
        Fixed Py = point.getY();

        Fixed num = (Ax * (Cy - Ay)) + ((Py - Ay) * (Cx - Ax)) - (Px * (Cy - Ay));
        Fixed denum = ((By - Ay) * (Cx - Ax)) - ((Bx - Ax) * (Cy - Ay));
        w1 = num / denum;
    }

    // Calculatiog the second vector
    {
        Fixed Ay = a.getY();
        Fixed By = b.getY();
        Fixed Cy = c.getY();
        Fixed Py = point.getY();

        Fixed num = Py - Ay - w1 * (By - Ay);
        Fixed denum = Cy - Ay;
        w2 = num / denum;
    }

    return ( w1 > 0 && w2 > 0 && ( w1 + w2 ) < 1 );
}
