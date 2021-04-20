#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <string>
#include <fstream>




using namespace ariel;

#include <string>

using namespace std;

TEST_CASE ("input and output cases") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    istringstream inputfirst{"700 [ km ]"};
    istringstream inputsec{"12 [ m ]"};
    istringstream input3{"245 [ cm ]"};
    istringstream input4{"5.5 [ kg ]"};
    istringstream input5{"80 [ g ]"};
    istringstream input6{"1 [ ton ]"};
    istringstream input7{"5 [ hour ]"};
    istringstream input8{"88 [ sec ]"};
    istringstream input9{"3 [ min ]"};
    istringstream input10{"33 [ USD ]"};
    istringstream input11{"87 [ ILS ]"};

    NumberWithUnits temp{0, "kg"};
    inputfirst>>temp;
            CHECK(temp == NumberWithUnits{700, "km"});
    inputsec>>temp;
            CHECK(temp == NumberWithUnits{12, "m"});
    input3>>temp;
            CHECK(temp == NumberWithUnits{245, "cm"});
    input4>>temp;
            CHECK(temp == NumberWithUnits{5.5, "kg"});
    input5>>temp;
            CHECK(temp == NumberWithUnits{80, "g"});
    input6>>temp;
            CHECK(temp == NumberWithUnits{1, "ton"});
    input7>>temp;
            CHECK(temp == NumberWithUnits{5, "hour"});
    input8>>temp;
            CHECK(temp == NumberWithUnits{88, "sec"});
    input9>>temp;
            CHECK(temp == NumberWithUnits{3, "min"});
    input10>>temp;
            CHECK(temp == NumberWithUnits{33, "USD"});
    input11>>temp;
            CHECK(temp == NumberWithUnits{87, "ILS"});

    ostringstream output1{};
    NumberWithUnits tempout{13, "kg"};
    output1<<tempout;
            CHECK( output1.str()== "13[kg]");
    ostringstream output2{};
    NumberWithUnits tempout2{444, "ton"};
    output2<<tempout2;
            CHECK( output2.str()== "444[ton]");
    ostringstream output3{};
    NumberWithUnits tempout3{4.5, "g"};
    output3<<tempout3;
            CHECK( output3.str()== "4.5[g]");



}


TEST_CASE ("km and m case") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{2, "km"};
    NumberWithUnits b{1000, "m"};


    NumberWithUnits aAddb = a + b;
            CHECK(aAddb == NumberWithUnits{3, "km"});
    NumberWithUnits bAdda = b+a;
            CHECK(aAddb == NumberWithUnits{3000, "m"});
    NumberWithUnits aMb = a - b;
            CHECK(aMb == NumberWithUnits{1, "km"});
    NumberWithUnits bMa = b-a;
            CHECK(bMa == NumberWithUnits{-1000, "m"});
    NumberWithUnits bMadouble =3*bMa;
            CHECK(bMadouble == NumberWithUnits{-3000, "m"});
    NumberWithUnits aMbdouble =3*aMb;
            CHECK(bMadouble == NumberWithUnits{-3, "km"});
    NumberWithUnits doubleaMb =aMb*3;
            CHECK(doubleaMb == NumberWithUnits{3, "km"});
            CHECK(a!=b);
            CHECK(b<a);
            CHECK(b<=a);
            CHECK(a>b);
            CHECK(a>=b);
            CHECK(aMbdouble!=bMadouble);
    NumberWithUnits bMadouble1 =(-3)*bMa;
            CHECK(bMadouble != NumberWithUnits{3000, "m"});
            CHECK(aMbdouble==bMadouble1);


    NumberWithUnits bOnri= -b;
    NumberWithUnits aOnri= -a;


            CHECK(+b == NumberWithUnits{1000, "m"});
            CHECK(+a == NumberWithUnits{2, "km"});

            CHECK(aOnri == NumberWithUnits{-2, "km"});
            CHECK(bOnri == NumberWithUnits{-1000, "m"});

            CHECK(aOnri<bOnri);

      a++;
            CHECK(a==NumberWithUnits{3, "km"});
      b++;
            CHECK(b==NumberWithUnits{1001, "m"});
      a+=a;
            CHECK(a==NumberWithUnits{6, "km"});
      a+=b;
            CHECK(a==NumberWithUnits{7.001, "km"});
      b-=a;
            CHECK(b==NumberWithUnits{-6000, "m"});

}

TEST_CASE ("m and cm case") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{20, "cm"};
    NumberWithUnits b{5, "m"};


    NumberWithUnits aAddb = a + b;
            CHECK(aAddb == NumberWithUnits{520, "cm"});
    NumberWithUnits bAdda = b + a;
            CHECK(aAddb == NumberWithUnits{5.2, "m"});
    NumberWithUnits aMb = a - b;
            CHECK(aMb == NumberWithUnits{-480, "cm"});
    NumberWithUnits bMa = b - a;
            CHECK(bMa == NumberWithUnits{4.8, "m"});
    NumberWithUnits bMadouble = (-3) * bMa;
            CHECK(bMadouble == NumberWithUnits{-14.4, "m"});
    NumberWithUnits aMbdouble = (-3) * aMb;
            CHECK(aMbdouble == NumberWithUnits{1440, "cm"});
    NumberWithUnits doubleaMb =aMb*(-3);
            CHECK(doubleaMb == NumberWithUnits{1440, "cm"});
            CHECK(a != b);
            CHECK(a < b);
            CHECK(b >= a);
            CHECK(a > bMadouble);
            CHECK(aMbdouble != bMadouble);


    NumberWithUnits bOnri = -b;
    NumberWithUnits aOnri = -a;


            CHECK(+b == NumberWithUnits{5, "m"});
            CHECK(+a == NumberWithUnits{20, "cm"});

            CHECK(aOnri == NumberWithUnits{-20, "cm"});
            CHECK(bOnri == NumberWithUnits{-5, "m"});
            CHECK(aOnri >bOnri);

    a++;
            CHECK(a == NumberWithUnits{21, "cm"});
    b++;
            CHECK(b == NumberWithUnits{6, "m"});
    a += a;
            CHECK(a == NumberWithUnits{42, "cm"});
    a += b;
            CHECK(a == NumberWithUnits{642, "cm"});
    b -= a;
            CHECK(b == NumberWithUnits{-0.42, "m"});
}

TEST_CASE ("km and cm case") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{16, "km"};
    NumberWithUnits b{10, "cm"};

    NumberWithUnits aAddb = a + b;
            CHECK(aAddb == NumberWithUnits{16.0001, "km"});
    NumberWithUnits bAdda = b + a;
            CHECK(aAddb == NumberWithUnits{1600010, "cm"});
    NumberWithUnits aMb = a - b;
            CHECK(aMb == NumberWithUnits{15.9999, "km"});
    NumberWithUnits bMa = b - a;
            CHECK(bMa == NumberWithUnits{-1599990, "cm"});
    NumberWithUnits bMadouble = (-3) * bMa;
            CHECK(bMadouble == NumberWithUnits{4799970, "cm"});
    NumberWithUnits aMbdouble = (-3) * aMb;
            CHECK(aMbdouble == NumberWithUnits{-47.9997, "km"});
            CHECK(a != b);
            CHECK(a >b);
            CHECK(b <= a);
            CHECK(a < bMadouble);
            CHECK(aMbdouble != bMadouble);


    NumberWithUnits bOnri = -b;
    NumberWithUnits bdouble = 10 * b;

    NumberWithUnits aOnri = -a;
    NumberWithUnits adouble = 10 * a;

            CHECK(aOnri == NumberWithUnits{-16, "km"});
            CHECK(adouble == NumberWithUnits{160, "km"});
            CHECK(bOnri == NumberWithUnits{-10, "cm"});
            CHECK(bdouble == NumberWithUnits{100, "cm"});

            CHECK(bOnri !=bdouble);
            CHECK(aOnri <bOnri);
            CHECK(bOnri < adouble);
            CHECK(adouble > bdouble);

    a++;
            CHECK(a == NumberWithUnits{17, "km"});
    b++;
            CHECK(b == NumberWithUnits{11, "cm"});
    a += a;
            CHECK(a == NumberWithUnits{34, "km"});
    a += b;
            CHECK(a == NumberWithUnits{34.00011, "km"});
    b -= a;
            CHECK(b == NumberWithUnits{-3400000, "cm"});
}

TEST_CASE ("g and kg case") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{10, "kg"};
    NumberWithUnits b{10, "g"};


    NumberWithUnits aAddb = a + b;
            CHECK(aAddb == NumberWithUnits{10.01, "kg"});
    NumberWithUnits bAdda = b + a;
            CHECK(aAddb == NumberWithUnits{10010, "g"});
    NumberWithUnits aMb = a - b;
            CHECK(aMb == NumberWithUnits{9.99, "kg"});
    NumberWithUnits bMa = b - a;
            CHECK(bMa == NumberWithUnits{-9990, "g"});

            CHECK(a != b);
            CHECK(a > b);
            CHECK(b <= a);


    NumberWithUnits bOnri = -b;
    NumberWithUnits aOnri = -a;


            CHECK(+b == NumberWithUnits{10, "g"});
            CHECK(+a == NumberWithUnits{10, "kg"});

            CHECK(aOnri == NumberWithUnits{-10, "kg"});
            CHECK(bOnri == NumberWithUnits{-10, "g"});
            CHECK(aOnri <bOnri);

    a++;
            CHECK(a == NumberWithUnits{11, "kg"});
    b++;
            CHECK(b == NumberWithUnits{11, "g"});
    a += a;
            CHECK(a == NumberWithUnits{22, "kg"});
    a += b;
            CHECK(a == NumberWithUnits{22.011, "kg"});
    b -= a;
            CHECK(b == NumberWithUnits{-22000, "g"});
}


TEST_CASE ("g and ton case") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{7, "g"};
    NumberWithUnits b{1, "ton"};


    NumberWithUnits aAddb = a + b;
            CHECK(aAddb == NumberWithUnits{1000007, "g"});
    NumberWithUnits bAdda = b + a;
            CHECK(aAddb == NumberWithUnits{1.000007, "ton"});
    NumberWithUnits aMb = a - b;
            CHECK(aMb == NumberWithUnits{-999993, "g"});
    NumberWithUnits bMa = b - a;
            CHECK(bMa == NumberWithUnits{0.999993, "ton"});
    NumberWithUnits bMadouble = (2) * bMa;
            CHECK(bMadouble == NumberWithUnits{1.999986, "ton"});

            CHECK(a != b);
            CHECK(a < b);
            CHECK(b >= a);
            CHECK(a < bMadouble);


    NumberWithUnits bOnri = -b;
    NumberWithUnits aOnri = -a;

            CHECK(aOnri == NumberWithUnits{-7, "g"});
            CHECK(bOnri == NumberWithUnits{-1, "ton"});

            CHECK(aOnri >bOnri);


    a++;
            CHECK(a == NumberWithUnits{8, "g"});
    b++;
            CHECK(b == NumberWithUnits{2, "ton"});
    a += a;
            CHECK(a == NumberWithUnits{16, "g"});
    a += b;
            CHECK(a == NumberWithUnits{2000016, "g"});
    b -= a;
            CHECK(b == NumberWithUnits{-0.000016, "ton"});
}

TEST_CASE ("kg and ton case") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{8, "kg"};
    NumberWithUnits b{2, "ton"};


    NumberWithUnits aAddb = a + b;
            CHECK(aAddb == NumberWithUnits{2008, "kg"});
    NumberWithUnits bAdda = b + a;
            CHECK(aAddb == NumberWithUnits{2.008, "ton"});
    NumberWithUnits aMb = a - b;
            CHECK(aMb == NumberWithUnits{-1992, "kg"});
    NumberWithUnits bMa = b - a;
            CHECK(bMa == NumberWithUnits{1.992, "ton"});
            CHECK(a != b);
            CHECK(a < b);
            CHECK(b >= a);


    NumberWithUnits bOnri = -b;
    NumberWithUnits aOnri = -a;

            CHECK(aOnri == NumberWithUnits{-8, "kg"});
            CHECK(bOnri == NumberWithUnits{-2, "ton"});
            CHECK(aOnri >bOnri);

    a++;
            CHECK(a == NumberWithUnits{9, "kg"});
    b++;
            CHECK(b == NumberWithUnits{3, "ton"});
    a += a;
            CHECK(a == NumberWithUnits{18, "kg"});
    a += b;
            CHECK(a == NumberWithUnits{3018, "kg"});
    b -= a;
            CHECK(b == NumberWithUnits{-0.018, "ton"});
}


TEST_CASE (" hour and min case") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{2, "hour"};
    NumberWithUnits b{8, "min"};


    NumberWithUnits aAddb = a + b;
            CHECK(aAddb == NumberWithUnits{2.13333, "hour"});
    NumberWithUnits bAdda = b + a;
            CHECK(aAddb == NumberWithUnits{127.9999, "min"});
    NumberWithUnits aMb = a - b;
            CHECK(aMb == NumberWithUnits{1.8667, "hour"});
    NumberWithUnits bMa = b - a;
            CHECK(bMa == NumberWithUnits{-112, "min"});
    NumberWithUnits bMadouble = (2) * bMa;
            CHECK(bMadouble == NumberWithUnits{-224, "min"});
    NumberWithUnits aMbdouble = (8) * aMb;
            CHECK(aMbdouble == NumberWithUnits{14.9336, "hour"});
            CHECK(a != b);
            CHECK(a > b);
            CHECK(b <= a);
            CHECK(a > bMadouble);
            CHECK(aMbdouble != bMadouble);


    NumberWithUnits bOnri = -b;
    NumberWithUnits aOnri = -a;

            CHECK(aOnri == NumberWithUnits{-2, "hour"});
            CHECK(bOnri == NumberWithUnits{-8, "min"});
            CHECK(aOnri <bOnri);

    a++;
            CHECK(a == NumberWithUnits{3, "hour"});
    b++;
            CHECK(b == NumberWithUnits{9, "min"});
    a += a;
            CHECK(a == NumberWithUnits{6, "hour"});
    a += b;
            CHECK(a == NumberWithUnits{6.15, "hour"});
    b -= a;
            CHECK(b == NumberWithUnits{-360, "min"});
}


TEST_CASE (" hour and sec case") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{2, "hour"};
    NumberWithUnits b{20, "sec"};


    NumberWithUnits aAddb = a + b;
            CHECK(aAddb == NumberWithUnits{2.005, "hour"});
    NumberWithUnits bAdda = b + a;
            CHECK(aAddb == NumberWithUnits{7220.0000, "sec"});
    NumberWithUnits aMb = a - b;
            CHECK(aMb == NumberWithUnits{1.9945, "hour"});
    NumberWithUnits bMa = b - a;
            CHECK(bMa == NumberWithUnits{-7179.9999, "sec"});
    NumberWithUnits bMadouble = (5) * bMa;
            CHECK(bMadouble == NumberWithUnits{-35899.9999, "sec"});
    NumberWithUnits aMbdouble = (2) * aMb;
            CHECK(aMbdouble == NumberWithUnits{3.989, "hour"});
            CHECK(a != b);
            CHECK(a > b);
            CHECK(b <= a);
            CHECK(a > bMadouble);


    NumberWithUnits bOnri = -b;
    NumberWithUnits aOnri = -a;


            CHECK(+b == NumberWithUnits{20, "sec"});
            CHECK(+a == NumberWithUnits{2, "hour"});

            CHECK(aOnri == NumberWithUnits{-2, "hour"});
            CHECK(bOnri == NumberWithUnits{-20, "sec"});
            CHECK(aOnri <bOnri);


    a++;
            CHECK(a == NumberWithUnits{3, "hour"});
    b++;
            CHECK(b == NumberWithUnits{21, "sec"});
    a += a;
            CHECK(a == NumberWithUnits{6, "hour"});
    a += b;
            CHECK(a == NumberWithUnits{6.0058, "hour"});

}


TEST_CASE (" min and sec case") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{12, "min"};
    NumberWithUnits b{4, "sec"};


    NumberWithUnits aAddb = a + b;
            CHECK(aAddb == NumberWithUnits{12.0666, "min"});
    NumberWithUnits bAdda = b + a;
            CHECK(aAddb == NumberWithUnits{724.0000, "sec"});
    NumberWithUnits aMb = a - b;
            CHECK(aMb == NumberWithUnits{11.9334, "min"});
    NumberWithUnits bMa = b - a;
            CHECK(bMa == NumberWithUnits{-716, "sec"});
    NumberWithUnits bMadouble = (-3) * bMa;
            CHECK(bMadouble == NumberWithUnits{2148, "sec"});
    NumberWithUnits aMbdouble = (3) * aMb;
            CHECK(aMbdouble == NumberWithUnits{35.8002, "min"});
            CHECK(a != b);
            CHECK(a > b);
            CHECK(b <= a);
            CHECK(b < bMadouble);
            CHECK(aMbdouble == bMadouble);


    NumberWithUnits bOnri = -b;
    NumberWithUnits bdouble = 10 * b;

    NumberWithUnits aOnri = -a;
    NumberWithUnits adouble = 10 * a;

            CHECK(aOnri == NumberWithUnits{-12, "min"});
            CHECK(adouble == NumberWithUnits{120, "min"});
            CHECK(bOnri == NumberWithUnits{-4, "sec"});
            CHECK(bdouble == NumberWithUnits{40, "sec"});

            CHECK(bOnri !=bdouble);
            CHECK(aOnri <bOnri);
            CHECK(bOnri < adouble);
            CHECK(adouble >bdouble);

    a++;
            CHECK(a == NumberWithUnits{13, "min"});
    b++;
            CHECK(b == NumberWithUnits{5, "sec"});
    a += a;
            CHECK(a == NumberWithUnits{26, "min"});
    a += b;
            CHECK(a == NumberWithUnits{26.0833, "min"});
    b -= a;
            CHECK(b == NumberWithUnits{-1560, "sec"});
}


TEST_CASE (" usd and ils case") {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{5.5, "USD"};
    NumberWithUnits b{4, "ILS"};


    NumberWithUnits aAddb = a + b;
            CHECK(aAddb == NumberWithUnits{6.7012, "USD"});
    NumberWithUnits bAdda = b + a;
            CHECK(aAddb == NumberWithUnits{22.315, "ILS"});
    NumberWithUnits aMb = a - b;
            CHECK(aMb == NumberWithUnits{4.2987, "USD"});
    NumberWithUnits bMa = b - a;
            CHECK(bMa == NumberWithUnits{-14.315, "ILS"});
    NumberWithUnits bMadouble = (-3) * bMa;
            CHECK(bMadouble == NumberWithUnits{42.945, "ILS"});
    NumberWithUnits aMbdouble = (6) * aMb;
            CHECK(aMbdouble == NumberWithUnits{25.7922, "USD"});
            CHECK(a != b);
            CHECK(a > b);
            CHECK(b <= a);
            CHECK(a <bMadouble);
            CHECK(aMbdouble != bMadouble);


    NumberWithUnits bOnri = -b;
    NumberWithUnits aOnri = -a;


            CHECK(+b == NumberWithUnits{4, "ILS"});
            CHECK(+a == NumberWithUnits{5.5, "USD"});

            CHECK(aOnri == NumberWithUnits{-5.5, "USD"});
            CHECK(bOnri == NumberWithUnits{-4, "ILS"});
            CHECK(aOnri <bOnri);

    a++;
            CHECK(a == NumberWithUnits{6.5, "USD"});
    b++;
            CHECK(b == NumberWithUnits{5, "ILS"});
    a += a;
            CHECK(a == NumberWithUnits{13, "USD"});
    a += b;
            CHECK(a == NumberWithUnits{14.5015, "USD"});
    b -= a;
            CHECK(b == NumberWithUnits{-43.2899, "ILS"});
}


TEST_CASE("Bad code") {


    string units[] = {"hour","kg","km","ILS", "min","cm","g","m", "ton","sec", "USD"};
    for (int i = 0; i < 10; ++i) {
        NumberWithUnits a{10, units[i]};
        NumberWithUnits b{10, units[i+1]};

        CHECK_THROWS_AS(a+b, std::invalid_argument);
        CHECK_THROWS_AS(a+=b, std::invalid_argument);
        CHECK_THROWS_AS(b+a, std::invalid_argument);
        CHECK_THROWS_AS(b+=a, std::invalid_argument);
        CHECK_THROWS_AS(a-b, std::invalid_argument);
        CHECK_THROWS_AS(b-a, std::invalid_argument);
        CHECK_THROWS_AS(b-=a, std::invalid_argument);
        CHECK_THROWS_AS(a-=b, std::invalid_argument);

    }

    CHECK_THROWS_AS(NumberWithUnits(3, "abc"), std::invalid_argument);

}






