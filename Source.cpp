#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>



using namespace std;



float x[10000];
float y[10000];
string polygon[100]; 
string NewPolygon[100]; 
string npolygon[100];


class poly;
class point;



void get_x(string s);
void get_y(string s);
void level2(string s);
void level_2(string s);
void Get_Polygons(string s);
float slope(float x1, float y1, float x2, float y2);
int Number_Polygons(string s);
int Total_Number_Points(string s);
float Maximum_X(string s);
float Minimum_X(string s);
float Maximum_Y(string s);
float Minimum_Y(string s);
void Enclosing_Rectangle(string s);
void Total_Redunant_Points(string s);
void Polygon_Points(string s, int i);
void Point_Polygons(string s, string point);
void List_Polygons_Points(string s, string x, int a);
void List_Points_Polygons(string s, string z, int a);
float Polygon_Perimeter(string s, int n);
void List_Triangles(string s);
void List_Rectangles(string s);
void List_Trapezoid(string s);
float distance(float x1, float x2, float y1, float y2);
void Inside_Rectangle(string s, string rec);
void Inside_circle(string s, string a, float R);
float Polygon_Area(string s, int n);
float Polygon_Area(string s);
void Polygons_Area_Range(string s, float minArea, float maxArea);
void Polygons_Enclosing_Point(string s, string a);
int Polygons_Enclosing_Point(string s, int i, point p);
string Is_Intersecting(string s, int o, int z);
string Intersecting_Group(string s, int i, int j, int k);
void Largest_Intersecting_Pair(string s, int &i, int &j);




int main()
{
	int PolygonID; int n;
	string s;
	getline(cin, s);
	string op; int b = 1;
	while (b == 1)
	{
		getline(cin, op);
		if (op == "Number_Polygons")
		{
			cout << Number_Polygons(s) << "\n";
		}
		if (op == "Total_Number_Points")
		{
			cout << Total_Number_Points(s) << "\n";
		}
		if (op == "Maximum_X")
		{
			cout << Maximum_X(s) << "\n";
		}
		if (op == "Minimum_X")
		{
			cout << Minimum_X(s) << "\n";
		}
		if (op == "Maximum_Y")
		{
			cout << Maximum_Y(s) << "\n";
		}
		if (op == "Minimum_Y")
		{
			cout << Minimum_Y(s) << "\n";
		}
		if (op == "Enclosing_Rectangle")
		{
			Enclosing_Rectangle(s); cout << "\n";
		}
		if (op == "Total_Redundant_Points")
		{
			Total_Redunant_Points(s); cout << "\n";
		}
		if (op.substr(0, 14) == "Polygon_Points")
		{
			op = op.substr(15);
			PolygonID = atof(op.c_str());
			Polygon_Points(s, PolygonID); cout << "\n";
		}
		if (op.substr(0, 14) == "Point_Polygons")
		{
			string point = op.substr(op.find('('), op.find(')') + 1 - op.find('('));
			Point_Polygons(s, point); cout << "\n";
		}
		if (op.substr(0, 20) == "List_Polygons_Points")
		{
			string x = op.substr(21, 5);
			op = op.substr(26);
			n = atof(op.c_str());
			List_Polygons_Points(s, x, n); cout << "\n";
		}
		if (op.substr(0, 20) == "List_Points_Polygons")
		{
			string x = op.substr(21, 5);
			op = op.substr(26);
			n = atof(op.c_str());
			List_Points_Polygons(s, x, n); cout << "\n";

		}
		if (op.substr(0, 17) == "Polygon_Perimeter")
		{
			op = op.substr(18);
			PolygonID = atof(op.c_str());
			cout << Polygon_Perimeter(s, PolygonID) << "\n";
		}
		if (op == "List_Triangles")
		{
			List_Triangles(s); cout << "\n";
		}
		if (op == "List_Rectangles")
		{
			List_Rectangles(s); cout << "\n";
		}
		if (op == "List_Trapezoid")
		{
			List_Trapezoid(s); cout << "\n";
		}
		if (op.substr(0, 16) == "Inside_Rectangle")
		{
			string rec = op.substr(17);
			Inside_Rectangle(s, rec); cout << "\n";
		}
		if (op.substr(0, 13) == "Inside_Circle")
		{
			string p = op.substr(14, op.find(')') - 13);
			string RR = op.substr(op.find_last_of(',') + 1);
			float R = atof(RR.c_str());
			Inside_circle(s, p, R); cout << "\n";
		}
		if (op.substr(0, 12) == "Polygon_Area")
		{
			op = op.substr(13);
			PolygonID = atof(op.c_str());
			cout << Polygon_Area(s, PolygonID) << "\n";
		}
		if (op.substr(0, 19) == "Polygons_Area_Range")
		{
			float minn, maxx; string minnn, maxxx;
			minnn = op.substr(20, op.find(',') - 20);
			maxxx = op.substr(op.find(',') + 1);
			minn = atof(minnn.c_str());
			maxx = atof(maxxx.c_str());
			Polygons_Area_Range(s, minn, maxx); cout << "\n";
		}
		if (op.substr(0, 24) == "Polygons_Enclosing_Point")
		{
			op = op.substr(25);
			Polygons_Enclosing_Point(s, op); cout << "\n";
		}
		if (op.substr(0, 15) == "Is_Intersecting")
		{
			string o, m;
			int p, q;
			o = op.substr(16, op.find(',') - 16);
			m = op.substr(op.find(',') + 1);
			p = atof(o.c_str());
			q = atof(m.c_str());
			cout<<Is_Intersecting(s, p, q); cout << "\n";
		}
		if (op.substr(0, 18) == "Intersecting_Group")
		{
			string i,j,k ;
			int ii,jj,kk;
			i = op.substr(19, op.find(',') - 19);
			j = op.substr(op.find(',') + 1,op.find_last_of(',')- op.find(',') - 1);
			k=op.substr(op.find_last_of(',') + 1);
			ii = atof(i.c_str());
			jj = atof(j.c_str());
			kk = atof(k.c_str());
			cout << Intersecting_Group(s,ii,jj,kk); cout << "\n";
		}
		if (op == "Largest_Intersecting_Pair")
		{
			int i, j;
			Largest_Intersecting_Pair(s, i, j);
			cout << i << "," << j << "\n";
		}
		if (op == "Quit")
		{
			b = 0;
		}
	}
}



//Classes
class point {
private:
	float x;
	float y;
public:
	point()
	{
		x = 0;
		y = 0;
	}
	point(string s)
	{
		string xx, yy;
		xx = s.substr(s.find_first_of('(') + 1, s.find_first_of(',') - s.find_first_of('(') - 1);
		yy = s.substr(s.find_first_of(',') + 1, s.find_first_of(')') - s.find_first_of('(') - 1);
		x = atof(xx.c_str());
		y = atof(yy.c_str());
	}
	void setx(float a)
	{
		x = a;
	}
	void sety(float a)
	{
		y = a;
	}
	float getx()
	{
		return x;
	}
	float gety()
	{
		return y;
	}
	float distance(point a)
	{
		float d = sqrt(pow(x - a.getx(), 2) + pow(y - a.gety(), 2));
	}
	void disp()
	{
		cout << "(" << x << "," << y << ")";
	}
};
class poly
{
private:
	point p[100];
	int Number_Points;

public:
	poly()
	{
		Number_Points = 0;
	}
	void set_points(point a, int i)
	{
		p[i] = a;
	}
	void set_points(string s)
	{
		get_x(s); get_y(s);
		for (int i = 0; i < Total_Number_Points(s); i++)
		{
			p[i].setx(x[i]);
			p[i].sety(y[i]);
		}
	}
	void set_Points(int n, point a[100])
	{
		for (int i = 0; i < n; i++)
		{
			p[i] = a[i];
		}
	}
	void setNoPoints(int a)
	{
		Number_Points = a;
	}
	int getNoPoints()
	{
		return Number_Points;
	}
};



//functions
void get_x(string s)
{
	int k = 0; string xString; int z;
	for (int i = 0; i <= s.find_last_of(')'); i++)
	{
		if (s[i] == '(')
		{
			for (int n = i; n <= s.find_last_of('_'); n++)
			{
				z = 0;
				if (s[n] == ',')
				{
					xString = (s.substr(i + 1, n - i - 1));
					x[k] = atof(xString.c_str());
					k = k + 1;
					z = 1;
				}
				if (z == 1)
					break;
			}
		}
	}
}

void get_y(string s)
{
	string yString; int l = 0; int v;
	for (int a = 0; a <= s.find_last_of(')'); a++)
	{
		if (s[a] == ',')
		{
			if (s[a + 1] != '(')
			{

				for (int b = a; b <= s.find_last_of(')'); b++)
				{
					v = 0;
					if (s[b] == ')')
					{
						yString = (s.substr(a + 1, b - a - 1));
						y[l] = atof(yString.c_str());
						l = l + 1;
						v = 1;
					}
					if (v == 1)
						break;
				}
			}
		}
	}
}

void Get_Polygons(string s)
{
	polygon[0] = " ";
	if (Number_Polygons(s) == 1)
	{
		polygon[1] = s.erase(0, 10);
	}
	else
	{
		polygon[1] = s.substr(s.find_first_of('('), (s.find_first_of(';') - s.find_first_of('(')));
	}
	polygon[Number_Polygons(s)] = s.substr(s.find_last_of(';') + 1, (s.find_last_of(')') - s.find_last_of(';')));
	int k = 2; int v; int n; int h = 0;
	for (int i = s.find_first_of(';'); i < s.find_last_of(';'); i++)
	{
		if (s[i] == ';')
		{
			for (n = i + 1; n <= s.find_last_of(';'); n++)
			{

				v = 0;
				if (s[n] == ';')
				{
					v = 1;
					polygon[k] = s.substr(i + 1, n - i - 1);
					k += 1;
				}
				if (v == 1)
					break;
			}
			i = n - 1;
		}

	}

}

void level2(string s)
{
	Get_Polygons(s); string ss;
	int a; int b, c; int i, n;
	for (int k = 1; k <= Number_Polygons(s); k++)              //polygons

	{
		ss = polygon[k];
		get_x(ss); get_y(ss); a = Total_Number_Points(ss) - 1;
		for (i = ss.find_last_of(')'); i >= 0; i--)               //metkaraar
		{
			if (ss[i] == ')')
			{
				b = 0;
				for (n = i; n >= 0; n--)
				{
					if (ss[n] == '(')
					{
						b = 1;
						if ((x[a] == x[a - 1] && y[a] == y[a - 1]))
						{
							ss = ss.erase(n - 1, i - n + 2);

							i = n;
						}
						a--;
					}
					if (b == 1)
						break;
				}
			}
		}

		get_x(ss); get_y(ss); a = Total_Number_Points(ss) - 1;            //slope
		for (i = ss.find_last_of(')'); i >= 0; i--)
		{
			if (ss[i] == ')')
			{
				b = 0;
				for (n = i; n >= 0; n--)
				{
					if (ss[n] == '(')
					{
						b = 1;
						if (a > 0 && a < Total_Number_Points(ss) - 1)
						{
							if (slope(x[a], y[a], x[a - 1], y[a - 1]) == slope(x[a - 1], y[a - 1], x[a + 1], y[a + 1]))
							{
								ss = ss.erase(n - 1, i - n + 2);
								i = n;
							}
							if (x[a] == x[a - 1] && x[a] == x[a + 1])
							{
								ss = ss.erase(n - 1, i - n + 2);
								i = n;
							}
						}
						a--;
					}
					if (b == 1)
						break;
				}
			}
		}
		get_x(ss); get_y(ss); a = Total_Number_Points(ss) - 1;
		if (x[0] == x[a] && y[0] == y[a])
			ss = ss.erase(ss.find_last_of('(') - 1, ss.find_last_of(')') - ss.find_last_of('(') + 2);
		get_x(ss); get_y(ss); a = Total_Number_Points(ss) - 1;
		if ((slope(x[0], y[0], x[1], y[1]) == slope(x[0], y[0], x[a], y[a])))
			ss = ss.erase(0, ss.find_first_of(')') + 2);
		get_x(ss); get_y(ss); a = Total_Number_Points(ss) - 1;
		if ((slope(x[0], y[0], x[a], y[a]) == slope(x[0], y[0], x[a - 1], y[a - 1])))
			ss = ss.erase(ss.find_last_of('(') - 1, ss.find_last_of(')') - ss.find_last_of('(') + 2);
		NewPolygon[k] = ss;
	}
}

void level_2(string s)
{
	Get_Polygons(s); string ss;
	int a; int b, c; int i, n;
	for (int k = 1; k <= Number_Polygons(s); k++)              //polygons

	{
		ss = polygon[k];
		get_x(ss); get_y(ss); a = Total_Number_Points(ss) - 1;
		for (i = ss.find_last_of(')'); i >= 0; i--)               //metkaraar
		{
			if (ss[i] == ')')
			{
				b = 0;
				for (n = i; n >= 0; n--)
				{
					if (ss[n] == '(')
					{
						b = 1;
						if ((x[a] == x[a - 1] && y[a] == y[a - 1]))
						{
							ss = ss.erase(n - 1, i - n + 2);

							i = n;
						}
						a--;
					}
					if (b == 1)
						break;
				}
			}
		}
		get_x(ss); get_y(ss); a = Total_Number_Points(ss) - 1;
		if (x[0] == x[a] && y[0] == y[a])
			ss = ss.erase(ss.find_last_of('(') - 1, ss.find_last_of(')') - ss.find_last_of('(') + 2);
		npolygon[k] = ss;
	}
}
float slope(float x1, float y1, float x2, float y2)
{
	float s = (y1 - y2) / (x1 - x2);
	return s;
}
int Number_Polygons(string s)
{
	int n = 0;
	for (int i = 0; i < s.find_last_of(')'); i++)
	{
		if (s[i] == ';')
		{
			n = n + 1;
		}
	}
	n = n + 1;
	return n;
}
int Total_Number_Points(string s)
{
	int n = 0;
	for (int i = 0; i <= s.find_last_of(')'); i++)
	{
		if (s[i] == ')')
		{
			n += 1;
		}
	}

	return n;
}
float Maximum_X(string s)
{
	get_x(s);
	float max = x[0];
	for (int n = 1; n < Total_Number_Points(s); n++)
	{
		if (x[n] > max)
		{
			max = x[n];
		}
	}
	return max;
}
float Minimum_X(string s)
{
	get_x(s);
	float min = x[0];
	for (int n = 1; n < Total_Number_Points(s); n++)
	{
		if (x[n] < min)
		{
			min = x[n];
		}
	}
	return min;
}
float Maximum_Y(string s)
{
	get_y(s);
	float max = y[0];
	for (int n = 1; n < Total_Number_Points(s); n++)
	{
		if (y[n] > max)
		{
			max = y[n];
		}
	}
	return max;
}
float Minimum_Y(string s)
{
	get_y(s);
	float min = y[0];
	for (int n = 1; n < Total_Number_Points(s); n++)
	{
		if (y[n] < min)
		{
			min = y[n];
		}
	}
	return min;
}
void Enclosing_Rectangle(string s)
{

	cout << "(" << Minimum_X(s) << "," << Minimum_Y(s) << "),(" << Maximum_X(s) << "," << Minimum_Y(s) << "),(" << Maximum_X(s) << "," << Maximum_Y(s) << "),(" << Minimum_X(s) << "," << Maximum_Y(s) << ")\n";
	return;

}
void Total_Redunant_Points(string s)
{
	int m = 0; int temp;
	Get_Polygons(s); level2(s);
	for (int i = 1; i <= Number_Polygons(s); i++)
	{
		temp = Total_Number_Points(polygon[i]) - Total_Number_Points(NewPolygon[i]);
		m = m + temp;
	}
	if (m == 0)
		cout << "None";
	else
		cout << m;
}
void Polygon_Points(string s, int i)
{
	level2(s);
	if (i == 0 || i > Number_Polygons(s))
	{
		cout << "None";
	}
	else
	{
		string polygon = NewPolygon[i];
		cout << polygon;
	}
}
void Point_Polygons(string s, string pointt)
{
	if (s.find(pointt) == -1)
	{
		cout << "None";
	}
	else
	{
		int temp[1000]; Get_Polygons(s); int m = 0;
		for (int i = 1; i <= Number_Polygons(s); i++)
		{
			if (polygon[i].find(pointt) != -1)
			{
				temp[m] = i;
				m++;
			}
		}
		m--;
		for (int n = 0; n <= m; n++)
		{
			if (n == m)
			{
				cout << temp[n];
			}
			else
			{
				cout << temp[n] << ",";
			}
		}
	}
}
void List_Polygons_Points(string s, string x, int a)
{
	int temp[100]; level2(s); int m = 0;
	if (x == "More ")
	{
		for (int i = 1; i <= Number_Polygons(s); i++)
		{
			if (Total_Number_Points(NewPolygon[i])>a)
			{
				temp[m] = i;
				m++;
			}
		}
	}
	if (x == "Less ")
	{
		for (int i = 1; i <= Number_Polygons(s); i++)
		{
			if (Total_Number_Points(NewPolygon[i])<a)
			{
				temp[m] = i;
				m++;
			}
		}
	}
	if (x == "Equal")
	{
		for (int i = 1; i <= Number_Polygons(s); i++)
		{
			if (Total_Number_Points(NewPolygon[i]) == a)
			{
				temp[m] = i;
				m++;
			}
		}
	}
	if (m == 0)
		cout << "None";
	else
	{
		m--;
		for (int n = 0; n <= m; n++)
		{
			if (n == m)
			{
				cout << temp[n];
			}
			else
			{
				cout << temp[n] << ",";
			}
		}
	}
}
void List_Points_Polygons(string s, string z, int a)
{
	level_2(s);
	float xx[10000], yy[10000]; int k = 0;
	for (int i = 1; i <= Number_Polygons(s); i++)
	{
		get_x(npolygon[i]); get_y(npolygon[i]);
		for (int n = 0; n < Total_Number_Points(npolygon[i]); n++)
		{

			xx[k] = x[n]; yy[k] = y[n];
			k++;
		}
	}
	point p[10000]; int m = 0; k--;// get_x(s); get_y(s);// 
	int count;
	if (z == "More ")
	{
		for (int f = 0; f <= k; f++)
		{
			count = 0;
			for (int c = 1; c <= Number_Polygons(s); c++)
			{
				get_x(npolygon[c]); get_y(npolygon[c]);
				for (int i = 0; i < Total_Number_Points(npolygon[c]); i++)
				{
					if (xx[f] == x[i] && yy[f] == y[i])
					{
						count++;
					}
				}
			}
			if (count > a)
			{
				p[m].setx(xx[f]); p[m].sety(yy[f]);
				m++;
			}
		}
	}
	if (z == "Less ")
	{
		for (int f = 0; f <= k; f++)
		{
			count = 0;
			for (int c = 1; c <= Number_Polygons(s); c++)
			{
				get_x(npolygon[c]); get_y(npolygon[c]);
				for (int i = 0; i < Total_Number_Points(npolygon[c]); i++)
				{
					if (xx[f] == x[i] && yy[f] == y[i])
					{
						count++;
					}
				}
			}
			if (count < a)
			{
				p[m].setx(xx[f]); p[m].sety(yy[f]);
				m++;
			}
		}
	}
	if (z == "Equal")
	{
		for (int f = 0; f <= k; f++)
		{
			count = 0;
			for (int c = 1; c <= Number_Polygons(s); c++)
			{
				get_x(npolygon[c]); get_y(npolygon[c]);
				for (int i = 0; i < Total_Number_Points(npolygon[c]); i++)
				{
					if (xx[f] == x[i] && yy[f] == y[i])
					{
						count++;
					}
				}
			}
			if (count == a)
			{
				p[m].setx(xx[f]); p[m].sety(yy[f]);
				m++;
			}
		}
	}
	if (m == 0)
		cout << "None";
	else
	{
		m--; float tempx, tempy, Rx, Ry; int g = 0;
		for (int ii = 0; ii<m; ii++)
		{
			tempx = p[ii].getx();
			tempy = p[ii].gety();
			for (int jj = ii + 1; jj < m; jj++)
			{
				if ((tempx == p[jj].getx()) && (tempy == p[jj].gety()))
				{
					for (int u = jj; u < m; u++)
					{
						Rx = p[u + 1].getx();
						Ry = p[u + 1].gety();
						p[u].setx(Rx);
						p[u].sety(Ry);
					}
					m--;
					jj--;
				}
			}
		}
		tempx = p[m].getx(); tempy = p[m].gety();
		for (int k = 0; k < m; k++)
		{
			if ((tempx == p[k].getx()) && (tempy == p[k].gety()))
			{
				m--;
			}
		}
		for (int n = 0; n <= m; n++)
		{
			if (n == m)
			{
				cout << "(" << p[n].getx() << "," << p[n].gety() << ")";
			}
			else
			{
				cout << "(" << p[n].getx() << "," << p[n].gety() << "),";
			}
		}
	}
}
float distance(float x1, float x2, float y1, float y2)
{
	float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	return dist;
}
float Polygon_Perimeter(string s, int n)
{
	float perm = 0; level2(s); float temp;
	get_x(NewPolygon[n]); get_y(NewPolygon[n]);
	temp = sqrt(pow(x[0] - x[Total_Number_Points(NewPolygon[n]) - 1], 2) + pow(y[0] - y[Total_Number_Points(NewPolygon[n]) - 1], 2));
	perm += temp;
	for (int i = 0; i < Total_Number_Points(NewPolygon[n]) - 1; i++)
	{
		perm += distance(x[i], x[i + 1], y[i], y[i + 1]);
	}
	return perm;
}
void List_Triangles(string s)
{
	level2(s); int temp[100]; int m = 0;
	for (int i = 1; i <= Number_Polygons(s); i++)
	{
		if (Total_Number_Points(NewPolygon[i]) == 3)
		{
			temp[m] = i;
			m++;
		}
	}
	m--;
	if (m < 0)
	{
		cout << "None";
	}
	else
	{
		for (int n = 0; n <= m; n++)
		{
			if (n == m)
			{
				cout << temp[n];
			}
			else
			{
				cout << temp[n] << ",";
			}
		}
	}
}
void List_Rectangles(string s)
{
	level2(s); int temp[100]; int m = 0;
	for (int i = 1; i <= Number_Polygons(s); i++)
	{
		if (Total_Number_Points(NewPolygon[i]) == 4)
		{
			get_x(NewPolygon[i]); get_y(NewPolygon[i]);
			if (((slope(x[0], y[0], x[1], y[1]) == slope(x[3], y[3], x[2], y[2])) && (slope(x[0], y[0], x[3], y[3]) == slope(x[1], y[1], x[2], y[2]))) && (distance(x[0], x[2], y[0], y[2]) == distance(x[3], x[1], y[3], y[1])))
			{
				temp[m] = i;
				m++;
			}
		}
	}
	m--;
	if (m < 0)
	{
		cout << "None";
	}
	else
	{
		for (int n = 0; n <= m; n++)
		{
			if (n == m)
			{
				cout << temp[n];
			}
			else
			{
				cout << temp[n] << ",";
			}
		}
	}
}
void List_Trapezoid(string s)
{
	level2(s); int temp[100]; int m = 0;
	for (int i = 1; i <= Number_Polygons(s); i++)
	{
		if (Total_Number_Points(NewPolygon[i]) == 4)
		{
			get_x(NewPolygon[i]); get_y(NewPolygon[i]);
			if (((slope(x[0], y[0], x[1], y[1]) == slope(x[3], y[3], x[2], y[2])) && (distance(x[0], x[1], y[0], y[1]) != distance(x[3], x[2], y[3], y[2]))) || ((slope(x[1], y[1], x[2], y[2]) == slope(x[0], y[0], x[3], y[3])) && (distance(x[1], x[2], y[1], y[2]) != distance(x[0], x[3], y[0], y[3]))))
			{
				temp[m] = i;
				m++;
			}
		}
	}
	m--;
	if (m < 0)
	{
		cout << "None";
	}
	else
	{
		for (int n = 0; n <= m; n++)
		{
			if (n == m)
			{
				cout << temp[n];
			}
			else
			{
				cout << temp[n] << ",";
			}
		}
	}
}
void Inside_Rectangle(string s, string rec)
{
	int temp[100]; level2(s); int m = 0;
	for (int i = 1; i <= Number_Polygons(s); i++)
	{
		if ((Maximum_X(rec) >= Maximum_X(NewPolygon[i])) && (Maximum_Y(rec) >= Maximum_Y(NewPolygon[i])) && (Minimum_X(rec) <= Minimum_X(NewPolygon[i])) && (Minimum_Y(rec) <= Minimum_Y(NewPolygon[i])))
		{
			temp[m] = i;
			m++;
		}
	}
	m--;
	if (m < 0)
	{
		cout << "None";
	}
	else
	{
		for (int n = 0; n <= m; n++)
		{
			if (n == m)
			{
				cout << temp[n];
			}
			else
			{
				cout << temp[n] << ",";
			}
		}
	}
}
void Inside_circle(string s, string a, float R)
{
	point p(a);
	int temp[100]; level2(s); int m = 0; int b;
	for (int i = 1; i <= Number_Polygons(s); i++)
	{
		b = 0;
		get_x(NewPolygon[i]); get_y(NewPolygon[i]);
		for (int n = 0; n < Total_Number_Points(NewPolygon[i]); n++)
		{
			if (distance(p.getx(), x[n], p.gety(), y[n]) <= R)
			{
				b = 1;
			}
			else
			{
				b = 0;
				break;
			}
		}
		if (b == 1)
		{
			temp[m] = i;
			m++;
		}
	}
	m--;
	if (m < 0)
	{
		cout << "None";
	}
	else
	{
		for (int n = 0; n <= m; n++)
		{
			if (n == m)
			{
				cout << temp[n];
			}
			else
			{
				cout << temp[n] << ",";
			}
		}
	}
}
float Polygon_Area(string s, int n)
{
	float area = 0; level2(s); get_x(NewPolygon[n]); get_y(NewPolygon[n]);
	for (int i = 0; i < Total_Number_Points(NewPolygon[n]) - 1; i++)
	{
		area += (x[i] * y[i + 1] - y[i] * x[i + 1]);
	}
	area += (x[Total_Number_Points(NewPolygon[n]) - 1] * y[0] - y[Total_Number_Points(NewPolygon[n]) - 1] * x[0]);
	area = abs(area / 2);
	return area;
}
float Polygon_Area(string s)
{
	float area = 0;  get_x(s); get_y(s);
	for (int i = 0; i < Total_Number_Points(s) - 1; i++)
	{
		area += (x[i] * y[i + 1] - y[i] * x[i + 1]);
	}
	area += (x[Total_Number_Points(s) - 1] * y[0] - y[Total_Number_Points(s) - 1] * x[0]);
	area = abs(area / 2);
	return area;
}
float Polygon_Area(point a, point b, point c)
{
	float area = 0;
	area += (a.getx()*b.gety()) - (a.gety()*b.getx());
	area += (b.getx()*c.gety()) - (b.gety()*c.getx());
	area += (c.getx()*a.gety()) - (c.gety()*a.getx());
	area = abs(area / 2);
	return area;
}
void Polygons_Area_Range(string s, float minArea, float maxArea)
{
	int temp[100]; level2(s); int m = 0;
	for (int i = 1; i <= Number_Polygons(s); i++)
	{
		if ((Polygon_Area(s, i) >= minArea) && (Polygon_Area(s, i) <= maxArea))
		{
			temp[m] = i;
			m++;
		}
	}
	m--;
	if (m < 0)
	{
		cout << "None";
	}
	else
	{
		for (int n = 0; n <= m; n++)
		{
			if (n == m)
			{
				cout << temp[n];
			}
			else
			{
				cout << temp[n] << ",";
			}
		}
	}
}
/*void Polygons_Enclosing_Point(string s, string a)
{
point p(a);
int temp[100]; level2(s); int m = 0; point b, c; float area ; int bb; int counter = 0;
for (int i = 1; i <= Number_Polygons(s); i++)
{
area = 0;
get_x(NewPolygon[i]); get_y(NewPolygon[i]);
for (int n = 0; n < Total_Number_Points(NewPolygon[i])-1; n++)
{
b.setx(x[n]); b.sety(y[n]); c.setx(x[n+1]); c.sety(y[n+1]);
area += Polygon_Area(p, b, c);
}
b.setx(x[0]); b.sety(y[0]); c.setx(x[Total_Number_Points(NewPolygon[i]) - 1]); c.sety(y[Total_Number_Points(NewPolygon[i]) - 1]);
area += Polygon_Area(p, b, c);
area = abs(area);
if (area == Polygon_Area(s, i))
{
temp[m] = i;
m++;
}
else if (area>Polygon_Area(s, i))
{
int b; int counter;
for (int i = 1; i <= Number_Polygons(s); i++)
{
b = 0; counter = 0;
get_x(NewPolygon[i]); get_y(NewPolygon[i]);
for (int n = 0; n < Total_Number_Points(NewPolygon[i]); n++)
{
if (p.getx() == x[n] && p.gety() == y[n])
{
temp[m] = i; m++;
b = 1;
}
}
if (b == 1)
continue;
for (int k = 0; k < Total_Number_Points(NewPolygon[i]) - 1; k++)
{
if (slope(x[k], y[k], p.getx(), p.gety()) == slope(p.getx(), p.gety(), x[k + 1], y[k + 1]))
{
temp[m] = i; m++;
b = 1;
}
}
if (slope(x[0], y[0], p.getx(), p.gety()) == slope(p.getx(), p.gety(), x[Total_Number_Points(NewPolygon[i]) - 1], y[Total_Number_Points(NewPolygon[i]) - 1]))
{
temp[m] = i; m++;
b = 1;
}
if (b == 1)
continue;
for (int v = 0; v < Total_Number_Points(NewPolygon[i]) - 1; v++)
{
if (((p.gety()>=y[v]) && (p.gety()<=y[v + 1])) || ((p.gety()<=y[v]) && (p.gety()>=y[v + 1])))
{
float xIntersec = ((x[v + 1] - x[v]) / (y[v + 1] - y[v]))*(p.gety() - y[v]) + x[v];
if (xIntersec >= p.getx())
{
counter++;
}
for (int h = 1; h < Total_Number_Points(NewPolygon[i]) - 1; h++)
{
if (xIntersec == x[h] && p.gety() == y[h])
{
if (((y[h + 1] > y[h]) && (y[h - 1] < y[h])) || ((y[h + 1] < y[h]) && (y[h - 1] > y[h])))
{
counter--;
break;
}
}
}
}
}
if (((p.gety() >= y[0]) && (p.gety() <= y[Total_Number_Points(NewPolygon[i]) - 1])) || ((p.gety() <= y[0]) && (p.gety() >= y[Total_Number_Points(NewPolygon[i]) - 1])))
{
float xIntersec = ((x[Total_Number_Points(NewPolygon[i]) - 1] - x[0]) / (y[Total_Number_Points(NewPolygon[i]) - 1] - y[0]))*(p.gety() - y[0]) + x[0];
if (xIntersec > p.getx())
{
counter++;
}
if (xIntersec == x[0] && p.gety() == y[0])
{
if (((y[1] >= y[0]) && (y[Total_Number_Points(NewPolygon[i]) - 1] <= y[0])) || ((y[1] <= y[0]) && (y[Total_Number_Points(NewPolygon[i]) - 1] >= y[0])))
{
counter--;
}
}
if (xIntersec == x[Total_Number_Points(NewPolygon[i]) - 1] && p.gety() == y[Total_Number_Points(NewPolygon[i]) - 1])
{
if (((y[0] >= y[Total_Number_Points(NewPolygon[i]) - 1]) && (y[Total_Number_Points(NewPolygon[i]) - 2] <= y[Total_Number_Points(NewPolygon[i]) - 1])) || ((y[0] <= y[Total_Number_Points(NewPolygon[i]) - 1]) && (y[Total_Number_Points(NewPolygon[i]) - 2] >= y[Total_Number_Points(NewPolygon[i]) - 1])))
{
counter--;
}
}
}
if (counter % 2 != 0)
{
temp[m] = i; m++;
b = 1;
}
if (b == 1)
continue;
}
}
}
m--;
if (m < 0)
{
cout << "None";
}
else
{
for (int n = 0; n <= m; n++)
{
if (n == m)
{
cout << temp[n];
}
else
{
cout << temp[n] << ",";
}
}
}
}*/
int Polygons_Enclosing_Point(string s, int i, point p)
{
	point b, c; float area; int pp = 1, q = 0;
	area = 0; get_x(s); get_y(s);
	for (int n = 0; n < Total_Number_Points(s) - 1; n++)
	{
		b.setx(x[n]); b.sety(y[n]); c.setx(x[n + 1]); c.sety(y[n + 1]);
		area += Polygon_Area(p, b, c);
	}
	b.setx(x[0]); b.sety(y[0]); c.setx(x[Total_Number_Points(s) - 1]); c.sety(y[Total_Number_Points(s) - 1]);
	area += Polygon_Area(p, b, c);
	area = abs(area);
	if (area == Polygon_Area(s, i))
	{
		return pp;
	}
	else
	{
		return q;
	}
}
void Polygons_Enclosing_Point(string s, string a)
{
	point p(a);
	int temp[100]; level2(s); int m = 0; int b; int counter; int c = 0;
	for (int i = 1; i <= Number_Polygons(s); i++)
	{
		b = 0; counter = 0;
		get_x(NewPolygon[i]); get_y(NewPolygon[i]);
		for (int n = 0; n < Total_Number_Points(NewPolygon[i]); n++)
		{
			if (p.getx() == x[n] && p.gety() == y[n])
			{
				temp[m] = i; m++;
				b = 1;
			}
		}
		if (b == 1)
			continue;
		for (int k = 0; k < Total_Number_Points(NewPolygon[i]) - 1; k++)
		{
			if (((p.gety() >= y[k]) && (p.gety() <= y[k + 1])) || ((p.gety() <= y[k]) && (p.gety() >= y[k + 1])))
			{
				if (slope(x[k], y[k], p.getx(), p.gety()) == slope(p.getx(), p.gety(), x[k + 1], y[k + 1]))
				{
					if (distance(x[k],p.getx(),y[k],p.gety())+ distance(x[k+1], p.getx(), y[k+1], p.gety())== distance(x[k], x[k+1], y[k], y[k+1]))
					{
						temp[m] = i; m++;
						b = 1;
					}
				}
			}
		}
		if (((p.gety() >= y[0]) && (p.gety() <= y[Total_Number_Points(NewPolygon[i]) - 1])) || ((p.gety() <= y[0]) && (p.gety() >= y[Total_Number_Points(NewPolygon[i]) - 1])))
		{
			if (slope(x[0], y[0], p.getx(), p.gety()) == slope(p.getx(), p.gety(), x[Total_Number_Points(NewPolygon[i]) - 1], y[Total_Number_Points(NewPolygon[i]) - 1]))
			{
				if (distance(x[0], p.getx(), y[0], p.gety()) + distance(x[Total_Number_Points(NewPolygon[i]) - 1], p.getx(), y[Total_Number_Points(NewPolygon[i]) - 1], p.gety()) == distance(x[0], x[Total_Number_Points(NewPolygon[i]) - 1], y[0], y[Total_Number_Points(NewPolygon[i]) - 1]))
				{
					temp[m] = i; m++;
					b = 1;
				}
			}
		}
		if (b == 1)
			continue;
		for (int v = 0; v < Total_Number_Points(NewPolygon[i]) - 1; v++)
		{
			if (((p.gety() >= y[v]) && (p.gety() <= y[v + 1])) || ((p.gety() <= y[v]) && (p.gety() >= y[v + 1])))
			{
				float xIntersec = ((x[v + 1] - x[v]) / (y[v + 1] - y[v]))*(p.gety() - y[v]) + x[v];
				if (xIntersec >= p.getx())
				{
					counter++;
					for (int h = 1; h < Total_Number_Points(NewPolygon[i]) - 1; h++)
					{
						if (xIntersec == x[h] && p.gety() == y[h])
						{
							if (c == 0)
							{
								if (((y[h + 1] >= y[h]) && (y[h - 1] <= y[h])) || ((y[h + 1] <= y[h]) && (y[h - 1] >= y[h])))
								{
									counter--;
									c = 1;
									break;
								}
							}
							if (c == 1)
							{
								c = 0;
								break;
							}
						}
					}
				}
			}
		}
		if (((p.gety() >= y[0]) && (p.gety() <= y[Total_Number_Points(NewPolygon[i]) - 1])) || ((p.gety() <= y[0]) && (p.gety() >= y[Total_Number_Points(NewPolygon[i]) - 1])))
		{
			float xIntersec = ((x[Total_Number_Points(NewPolygon[i]) - 1] - x[0]) / (y[Total_Number_Points(NewPolygon[i]) - 1] - y[0]))*(p.gety() - y[0]) + x[0];
			if (xIntersec > p.getx())
			{
				counter++;
				if (xIntersec == x[0] && p.gety() == y[0])
				{
					if (((y[1] >= y[0]) && (y[Total_Number_Points(NewPolygon[i]) - 1] <= y[0])) || ((y[1] <= y[0]) && (y[Total_Number_Points(NewPolygon[i]) - 1] >= y[0])))
					{
						counter--;
					}
				}
				if (xIntersec == x[Total_Number_Points(NewPolygon[i]) - 1] && p.gety() == y[Total_Number_Points(NewPolygon[i]) - 1])
				{
					if (((y[0] >= y[Total_Number_Points(NewPolygon[i]) - 1]) && (y[Total_Number_Points(NewPolygon[i]) - 2] <= y[Total_Number_Points(NewPolygon[i]) - 1])) || ((y[0] <= y[Total_Number_Points(NewPolygon[i]) - 1]) && (y[Total_Number_Points(NewPolygon[i]) - 2] >= y[Total_Number_Points(NewPolygon[i]) - 1])))
					{
						counter--;
					}
				}
			}
		}
		if (counter % 2 != 0)
		{
			temp[m] = i; m++;
			b = 1;
		}
		if (b == 1)
			continue;
	}
	m--;
	if (m < 0)
	{
		cout << "None";
	}
	else
	{
		for (int n = 0; n <= m; n++)
		{
			if (n == m)
			{
				cout << temp[n];
			}
			else
			{
				cout << temp[n] << ",";
			}
		}
	}
}
string Is_Intersecting(string s, int o, int z)
{
	level2(s);
	float xx[10000], yy[10000]; 
	get_x(NewPolygon[z]); get_y(NewPolygon[z]);
	for (int n = 0; n < Total_Number_Points(NewPolygon[z]); n++)
	{
	    xx[n] = x[n]; yy[n] = y[n];
	}
	for(int f= 0; f < Total_Number_Points(NewPolygon[z]); f++)
	{ 
		point p; p.setx(xx[f]); p.sety(yy[f]);
		int temp[100]; level2(s); int m = 0; int b; int counter; int c = 0;
			b = 0; counter = 0;
			get_x(NewPolygon[o]); get_y(NewPolygon[o]);
			for (int n = 0; n < Total_Number_Points(NewPolygon[o]); n++)
			{
				if (p.getx() == x[n] && p.gety() == y[n])
				{
					return "TRUE";
				}
			}
			for (int k = 0; k < Total_Number_Points(NewPolygon[o]) - 1; k++)
			{
				if (((p.gety() > y[k]) && (p.gety() < y[k + 1])) || ((p.gety() < y[k]) && (p.gety() > y[k + 1])))
				{
					if (slope(x[k], y[k], p.getx(), p.gety()) == slope(p.getx(), p.gety(), x[k + 1], y[k + 1]))
					{
						if (distance(x[k], p.getx(), y[k], p.gety()) + distance(x[k + 1], p.getx(), y[k + 1], p.gety()) == distance(x[k], x[k + 1], y[k], y[k + 1]))
						return "TRUE";
					}
				}
			}
			if (((p.gety() > y[0]) && (p.gety() < y[Total_Number_Points(NewPolygon[o]) - 1])) || ((p.gety() < y[0]) && (p.gety() > y[Total_Number_Points(NewPolygon[o]) - 1])))
			{
				if (slope(x[0], y[0], p.getx(), p.gety()) == slope(p.getx(), p.gety(), x[Total_Number_Points(NewPolygon[o]) - 1], y[Total_Number_Points(NewPolygon[o]) - 1]))
				{
					if (distance(x[0], p.getx(), y[0], p.gety()) + distance(x[Total_Number_Points(NewPolygon[o]) - 1], p.getx(), y[Total_Number_Points(NewPolygon[o]) - 1], p.gety()) == distance(x[0], x[Total_Number_Points(NewPolygon[o]) - 1], y[0], y[Total_Number_Points(NewPolygon[o]) - 1]))
					return "TRUE";
				}
			}
			for (int v = 0; v < Total_Number_Points(NewPolygon[o]) - 1; v++)
			{
				if (((p.gety() >= y[v]) && (p.gety() <= y[v + 1])) || ((p.gety() <= y[v]) && (p.gety() >= y[v + 1])))
				{
					float xIntersec = ((x[v + 1] - x[v]) / (y[v + 1] - y[v]))*(p.gety() - y[v]) + x[v];
					if (xIntersec >= p.getx())
					{
						counter++;
						for (int h = 1; h < Total_Number_Points(NewPolygon[o]) - 1; h++)
						{
							if (xIntersec == x[h] && p.gety() == y[h])
							{
								if (c == 0)
								{
									if (((y[h + 1] >= y[h]) && (y[h - 1] <= y[h])) || ((y[h + 1] <= y[h]) && (y[h - 1] >= y[h])))
									{
										counter--;
										c = 1;
										break;
									}
								}
								if (c == 1)
								{
									c = 0;
									break;
								}
							}
						}
					}
				}
			}
			if (((p.gety() >= y[0]) && (p.gety() <= y[Total_Number_Points(NewPolygon[o]) - 1])) || ((p.gety() <= y[0]) && (p.gety() >= y[Total_Number_Points(NewPolygon[o]) - 1])))
			{
				float xIntersec = ((x[Total_Number_Points(NewPolygon[o]) - 1] - x[0]) / (y[Total_Number_Points(NewPolygon[o]) - 1] - y[0]))*(p.gety() - y[0]) + x[0];
				if (xIntersec > p.getx())
				{
					counter++;
					if (xIntersec == x[0] && p.gety() == y[0])
					{
						if (((y[1] >= y[0]) && (y[Total_Number_Points(NewPolygon[o]) - 1] <= y[0])) || ((y[1] <= y[0]) && (y[Total_Number_Points(NewPolygon[o]) - 1] >= y[0])))
						{
							counter--;
						}
					}
					if (xIntersec == x[Total_Number_Points(NewPolygon[o]) - 1] && p.gety() == y[Total_Number_Points(NewPolygon[o]) - 1])
					{
						if (((y[0] >= y[Total_Number_Points(NewPolygon[o]) - 1]) && (y[Total_Number_Points(NewPolygon[o]) - 2] <= y[Total_Number_Points(NewPolygon[o]) - 1])) || ((y[0] <= y[Total_Number_Points(NewPolygon[o]) - 1]) && (y[Total_Number_Points(NewPolygon[o]) - 2] >= y[Total_Number_Points(NewPolygon[o]) - 1])))
						{
							counter--;
						}
					}
				}
			}
			if (counter % 2 != 0)
			{
				return "TRUE";
			}
	}
	int temppp = z;
	z = o;
	o = temppp;
	get_x(NewPolygon[z]); get_y(NewPolygon[z]);
	for (int n = 0; n < Total_Number_Points(NewPolygon[z]); n++)
	{
		xx[n] = x[n]; yy[n] = y[n];
	}
	for (int f = 0; f < Total_Number_Points(NewPolygon[z]); f++)
	{
		point p; p.setx(xx[f]); p.sety(yy[f]);
		int temp[100]; level2(s); int m = 0; int b; int counter; int c = 0;
		b = 0; counter = 0;
		get_x(NewPolygon[o]); get_y(NewPolygon[o]);
		for (int n = 0; n < Total_Number_Points(NewPolygon[o]); n++)
		{
			if (p.getx() == x[n] && p.gety() == y[n])
			{
				return "TRUE";
			}
		}
		for (int k = 0; k < Total_Number_Points(NewPolygon[o]) - 1; k++)
		{
			if (((p.gety() > y[k]) && (p.gety() < y[k + 1])) || ((p.gety() < y[k]) && (p.gety() > y[k + 1])))
			{
				if (slope(x[k], y[k], p.getx(), p.gety()) == slope(p.getx(), p.gety(), x[k + 1], y[k + 1]))
				{
					if (distance(x[k], p.getx(), y[k], p.gety()) + distance(x[k + 1], p.getx(), y[k + 1], p.gety()) == distance(x[k], x[k + 1], y[k], y[k + 1]))
					return "TRUE";
				}
			}
		}
		if (((p.gety() > y[0]) && (p.gety() < y[Total_Number_Points(NewPolygon[o]) - 1])) || ((p.gety() < y[0]) && (p.gety() > y[Total_Number_Points(NewPolygon[o]) - 1])))
		{
			if (slope(x[0], y[0], p.getx(), p.gety()) == slope(p.getx(), p.gety(), x[Total_Number_Points(NewPolygon[o]) - 1], y[Total_Number_Points(NewPolygon[o]) - 1]))
			{
				if (distance(x[0], p.getx(), y[0], p.gety()) + distance(x[Total_Number_Points(NewPolygon[o]) - 1], p.getx(), y[Total_Number_Points(NewPolygon[o]) - 1], p.gety()) == distance(x[0], x[Total_Number_Points(NewPolygon[o]) - 1], y[0], y[Total_Number_Points(NewPolygon[o]) - 1]))
				return "TRUE";
			}
		}
		for (int v = 0; v < Total_Number_Points(NewPolygon[o]) - 1; v++)
		{
			if (((p.gety() >= y[v]) && (p.gety() <= y[v + 1])) || ((p.gety() <= y[v]) && (p.gety() >= y[v + 1])))
			{
				float xIntersec = ((x[v + 1] - x[v]) / (y[v + 1] - y[v]))*(p.gety() - y[v]) + x[v];
				if (xIntersec >= p.getx())
				{
					counter++;
					for (int h = 1; h < Total_Number_Points(NewPolygon[o]) - 1; h++)
					{
						if (xIntersec == x[h] && p.gety() == y[h])
						{
							if (c == 0)
							{
								if (((y[h + 1] >= y[h]) && (y[h - 1] <= y[h])) || ((y[h + 1] <= y[h]) && (y[h - 1] >= y[h])))
								{
									counter--;
									c = 1;
									break;
								}
							}
							if (c == 1)
							{
								c = 0;
								break;
							}
						}
					}
				}
			}
		}
		if (((p.gety() >= y[0]) && (p.gety() <= y[Total_Number_Points(NewPolygon[o]) - 1])) || ((p.gety() <= y[0]) && (p.gety() >= y[Total_Number_Points(NewPolygon[o]) - 1])))
		{
			float xIntersec = ((x[Total_Number_Points(NewPolygon[o]) - 1] - x[0]) / (y[Total_Number_Points(NewPolygon[o]) - 1] - y[0]))*(p.gety() - y[0]) + x[0];
			if (xIntersec > p.getx())
			{
				counter++;
				if (xIntersec == x[0] && p.gety() == y[0])
				{
					if (((y[1] >= y[0]) && (y[Total_Number_Points(NewPolygon[o]) - 1] <= y[0])) || ((y[1] <= y[0]) && (y[Total_Number_Points(NewPolygon[o]) - 1] >= y[0])))
					{
						counter--;
					}
				}
				if (xIntersec == x[Total_Number_Points(NewPolygon[o]) - 1] && p.gety() == y[Total_Number_Points(NewPolygon[o]) - 1])
				{
					if (((y[0] >= y[Total_Number_Points(NewPolygon[o]) - 1]) && (y[Total_Number_Points(NewPolygon[o]) - 2] <= y[Total_Number_Points(NewPolygon[o]) - 1])) || ((y[0] <= y[Total_Number_Points(NewPolygon[o]) - 1]) && (y[Total_Number_Points(NewPolygon[o]) - 2] >= y[Total_Number_Points(NewPolygon[o]) - 1])))
					{
						counter--;
					}
				}
			}
		}
		if (counter % 2 != 0)
		{
			return "TRUE";
		}
	}
	return "FALSE";
}
string Intersecting_Group(string s, int i, int j, int k)
{
	if (Is_Intersecting(s, i, j) == "TRUE"&& Is_Intersecting(s, i, k) == "TRUE"&& Is_Intersecting(s, i, j) == "TRUE" && Is_Intersecting(s, j, k) == "TRUE")
	{
		return "TRUE";
	}
	return "FALSE";
}
void Largest_Intersecting_Pair(string s, int &i, int &j)
{
	float max = 0;
	for (int n = 1; n <= Number_Polygons(s); n++)
	{
		for (int c = 1; c <= Number_Polygons(s); c++)
		{
			if (n == c)
				continue;
			else if (Is_Intersecting(s, n, c) == "TRUE")
			{
				if ((Polygon_Area(s, n) + Polygon_Area(s, c)) > max)
				{
					max = (Polygon_Area(s, n) + Polygon_Area(s, c));
					i = n; j = c;
				}
			}
		}
	}
}