#include <algorithm>
#include <vector>
#include <string>
#include <utility>



// parsowanie danych wejsciowych ---> zapis w formacie vector <tuple<int, string, string, string> >  : rok, nazwa, wartosc, poczta
// zapytania w formacie vector<pair<int, int> >
// wyszukiwanie danych po przedziałach za pomocą lower_bound i upper_bound

using namespace std;


using Query = pair<int, int>;
using Stamp = tuple<int, string, string, string>;
using Stamp_Const_Iter = vector<Stamp>::const_iterator;


vector<Stamp> get_stamps_data();
vector<Query> get_queries();
/* Wczytaj wejscie - znajdz miejsce, gdzie koncza sie dane o znaczkach, a rozpoczynaja sie zapytania
 * przechowuj wczytane dane w stringu (ewentualnie stringstream) i próbuj parsować do dwóch formatów:
 * Query albo Stamp.
 */
void parse_input(vector<Stamp> & stamps, vector<Query> & queries);

/*
 * Funkcja zwraca parę iteratorów, które określają początek i koniec sekwencji znaczków z przedziału lat,
 * określonego w zapytaniu query.
 */
pair<Stamp_Const_Iter, Stamp_Const_Iter> query_response(vector<Stamp> & stamps, Query query) {
	Stamp_Const_Iter start = lower_bound(stamps.begin(), stamps.end(), get<0>(query));
	Stamp_Const_Iter end = upper_bound(stamps.begin(), stamps.end(), get<1>(query));

	return pair<Stamp_Const_Iter, Stamp_Const_Iter> (start, end);
}


/*
 * Funkcja wypisująca wszystkie znaczki pocztowe z przedziału określonego przez iteratory
 * CZY NIE TRZEBA PRZEFORMATOWAĆ POSZCZEGÓLNYCH ELEMENTÓW WYJSCIA? (SPACJE!)
*/
void print_stamps (pair<Stamp_Const_Iter, Stamp_Const_Iter> range) {
	for (auto it = range.first; it != range.second; ++it)
		cout << get<0>(it) << get<1>(it) << get<2>(it) << get<3>(it) << endl;
}

int main() {
	vector<Stamp> stamps;
	vector<Query> queries;

	//wczytaj dane
	parse_input(stamps, queries);
	// TODO: dodac dodatkowe sortowanie w przypadku tego samego roku po znakach alfabetu
	sort(stamps.begin(), stamps.end(),
	[](auto const & a, auto const & b) { return get<0>(a) < get<0>(b);});
	// odpowiadaj za zapytania
	for (auto q : queries)
		print_stamps(query_response(stamps, q));

	return 0;
}