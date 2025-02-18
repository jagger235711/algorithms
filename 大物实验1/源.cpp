#include<iostream>
#include<cmath>
using namespace std;
constexpr auto pi = 3.1415;;
constexpr auto uD1 = 0.02;;
constexpr auto uD2 = 0.02;;
constexpr auto uH =  0.02;;

int main()
{
    float a, b, c, d, e, f, v;
    cout << "请输入零点读数" << endl;
    cin >> v;
    cout << endl;
   /* cout << "请输入高h" << endl;
    cin >> a >> b >> c >> d >> e >> f;
    cout << endl;
    float g, h, i, j, k, l;
    cout << "请输入内径d" << endl;
    cin >> g >> h >> i >> j >> k >> l;
    cout << endl;
    float m, n, o, p, q, r;
    cout << "请输入外径d" << endl;
    cin >> m >> n >> o >> p >> q >> r;
    cout << endl;*/
    double s, t, u;
    cin >> s;  //(a + b + c + d + e + f) / 6;
    cin >> t;  //(g + h + i + j + k + l) / 6;
    cin >> u;  //(m + n + o + p + q + r) / 6;
    cout << "高的平均值为：" << s << "  内径的平均值为：" << t << "  外径的平均值为：" << u << endl;
    double V, D1, D2, H,E, uV;
    H = s - v; D2 = t - v; D1 = u - v;
    V = pi / 4 * (D1 * D1 - D2 * D2) * H;
    
    E = (2 * D2 * uD2 / (D2 * D2 - D1 * D1)) * (2 * D2 * uD2 / (D2 * D2 - D1 * D1)) + (-2 * D1 * uD1 / (D2 * D2 - D1 * D1)) * (-2 * D1 * uD1 / (D2 * D2 - D1 * D1)) + (uH / H) * (uH / H);
    uV = E * V * V;

    cout << "高的修正测量值为：" << H << "  内径的修正测量值为：" << D2 << "  外径的修正测量值为：" << D1 << endl << "  空心圆柱体积为：" << V << "  体积的相对不确定度的平方为：" << E << endl << "   体积的不确定度的平方为" << uV << endl;
    cout << "（注意不确定度是平方，需要你自己开方）" << endl;
}