#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <functional>

constexpr double EPS = 1e-8;


double R0 = 0.35;
double Tw = 10000.;
double T0 = 10000.;
double k0 = 0.0008;
double c = 3e10;
int p = 4;

struct Range
{
    double start = 0.0;
    double stop;
    double step;

    Range(double _stop, double _step) : stop(_stop), step(_step)
    {

    }
};

struct SLAE
{
    std::function<double(double, double, double)> first;
    std::function<double(double, double, double)> second;
    double u0;
    double v0;

    SLAE(std::function<double(double, double, double)> _first,
        std::function<double(double, double, double)> _second,
        double _u0, double _v0)
        : first(_first), second(_second), u0(_u0), v0(_v0)
    {
    }

    SLAE(const SLAE& fcopy) = default;
};

double T(double z)
{
    return (Tw - T0) * pow(z, p) + T0;
}

double k(double z)
{
    double tmp = T(z) / 300.;
    return k0 * tmp * tmp;
}

double up(double z)
{
    return (3.084 * 1e-4) / (exp(47990. / T(z)) - 1);
}

using namespace std;

double ud(double z, double u, double f)
{
    return -f * 3. * k(z) * R0 / c;
}

double fd(double z, double u, double f)
{
    if (z == 0.0)
        return R0 * c * k(z) * (up(z) - u) / 2.0;
    return R0 * c * k(z) * (up(z) - u) - f / z;
}

std::pair<vector<double>, vector<double>> runge(const SLAE& _SLAE, const Range& range)
{
    std::pair<vector<double>, vector<double>> res;

    double yn = _SLAE.u0;
    double zn = _SLAE.v0;

    res.first.push_back(yn);
    res.second.push_back(zn);

    double h = range.step;

    double tmp = h / 2.;

    for (double cur = range.start; cur <= range.stop; cur += h)
    {
        double k1 = h * _SLAE.first (cur, yn, zn);
        double q1 = h * _SLAE.second(cur, yn, zn);

        double k2 = h * _SLAE.first (cur + tmp, yn + k1 / 2., zn + q1 / 2.);
        double q2 = h * _SLAE.second(cur + tmp, yn + k1 / 2., zn + q1 / 2.);

        double k3 = h * _SLAE.first (cur + tmp, yn + k2 / 2., zn + q2 / 2.);
        double q3 = h * _SLAE.second(cur + tmp, yn + k2 / 2., zn + q2 / 2.);

        double k4 = h * _SLAE.first (cur + h, yn + k3, zn + q3);
        double q4 = h * _SLAE.second(cur + h, yn + k3, zn + q3);

        res.first.push_back(yn += (k1 + 2. * k2 + 2. * k3 + k4) / 6.);
        res.second.push_back(zn += (q1 + 2. * q2 + 2. * q3 + q4) / 6.);
    }

    return res;
}

double right_cond(double u1, double F1)
{
   // cout << u1 << " " << F1 << std::endl;
    return F1 - 0.393 * c * u1;
}

double shooting_help(const SLAE& _SLAE, const Range& range)
{
    std::pair<vector<double>, vector<double>> tmp = runge(_SLAE, range);
    //cout << right_cond(tmp.first[tmp.first.size() - 1], tmp.second[tmp.second.size() - 1]) << std::endl;
    return right_cond(*tmp.first.rbegin(), *tmp.second.rbegin());
}

double bisect(double left, double right, std::function<double(double)> equation)
{
    double vleft, vright;

    if (fabs((vleft = equation(left))) < EPS)
        return left;
    if (fabs((vright = equation(right))) < EPS)
        return right;


    do
    {
        double mid = (left + right) / 2.0;
        double val = equation(mid);

        if (fabs(val) < EPS)
        {
            return mid;
        }
        else if (val * vleft < 0.0)
        {
            right = mid;
            vright = val;
        }
        else
        {
            left = mid;
            vleft = val;
        }

    } while (left < right);

    return left - 10.0;
}

std::pair<vector<double>, vector<double>> shooting(SLAE _SLAE, const Range& range)
{
    _SLAE.u0 = 0.0;
    _SLAE.v0 = 0.0;

    double h = 0.05 * up(0);

    double prev = shooting_help(_SLAE, range);
    _SLAE.u0 += h;
    double cur = prev;

    for (; cur * prev > 0.0; _SLAE.u0 += h)
    {
        cout << _SLAE.u0 / up(0) << std::endl;
        prev = cur;
        cur = shooting_help(_SLAE, range);
        //cout << _SLAE.u0 - h << " " << _SLAE.u0 << std::endl;
    }
 

    cout << (_SLAE.u0 = bisect(_SLAE.u0 - 2 * h, _SLAE.u0 - h,
        [&](double x)
        {
            SLAE tmp = _SLAE;
            tmp.u0 = x;
            tmp.v0 = 0.;

            return shooting_help(tmp, range);
        }
    ));

    // cout << shooting_help(_SLAE, range);

    return runge(_SLAE, range);
}


void print_table(ostream& stream, const std::pair<vector<double>, vector<double>> res, const Range& range)
{
    cout << "u     F" << "\n";

    double cur = range.start;

    for (int i = 0; i < res.second.size(); i++)
    { 
        stream << cur << " " <<  up(cur)<< " " <<  res.first[i]  << " " << res.second[i] << "\n";
        cur += range.step;
    }
}

void create_params(SLAE slae, Range &range)
{
    {
        ofstream str("R.txt");
        for (R0 = 0.30; R0 <= 0.40; R0 += 0.01)
        {
            std::pair<vector<double>, vector<double>> tmp(shooting(slae, range));
            str << R0 << " " << tmp.first[0] << "\n";
        }

        R0 = 0.35;
    }

    {
        ofstream str("T0.txt");
        for (T0 = 5e3; T0 <= 15e3; T0 += 1e3)
        {
            std::pair<vector<double>, vector<double>> tmp(shooting(slae, range));
            str << T0 << " " << tmp.first[0] << "\n";

        }

        T0 = 1e4;
    }

    {
        ofstream str("Tw.txt");
        for (Tw = 500; Tw <= 4000; Tw += 500)
        {
            std::pair<vector<double>, vector<double>> tmp(shooting(slae, range));
            str << Tw << " " << tmp.first[0] << "\n";
        }

        Tw = 2000.;
    }

    {
        ofstream str("k0.txt");
        for (k0 = 0.0004; k0 <= 0.0014; k0 += 1e-4)
        {
            std::pair<vector<double>, vector<double>> tmp(shooting(slae, range));
          
            
            str << k0 << " " << tmp.first[0] << "\n";
        }

        k0 = 8e-4;
    }

    {
        ofstream str("p.txt");
        for (p = 4; p <= 15; p++)
        {
            std::pair<vector<double>, vector<double>> tmp(shooting(slae, range));
            str << p << " " << tmp.first[0] << "\n";
        }

        p = 4;
    }
}

int main()
{
    Range range(1.0, 1e-2);
    SLAE  slae(ud, fd, 0.0, 0.0);

    std::pair<vector<double>, vector<double>> res = shooting(slae, range);

    ofstream os("res.txt");
    print_table(os, res, range);
    os.close();

    create_params(slae, range);

    return 0;
}
