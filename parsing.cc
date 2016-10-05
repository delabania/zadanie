#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <boost/regex.hpp>


// parsowanie danych wejsciowych ---> zapis w formacie vector <tuple<int, string, string, string> >  : rok, nazwa, wartosc, poczta
// zapytania w formacie vector<pair<int, int> >
// wyszukiwanie danych po przedziałach za pomocą lower_bound i upper_bound

using Query = std::pair<int, int>;
using Stamp = std::tuple<int, std::string, std::string, std::string>;
using Stamp_Const_Iter = std::vector<Stamp>::const_iterator;


void print_error(int n, std::string &s) {
	std::cerr << "Error in line " << line_number << ":" << input_line << std::endl;
}
/* Wczytaj wejscie - znajdz miejsce, gdzie koncza sie dane o znaczkach, a rozpoczynaja sie zapytania
 * przechowuj wczytane dane w stringu (ewentualnie stringstream) i próbuj parsować do dwóch formatów:
 * Query albo Stamp.
 */
void parse_input(std::vector<Stamp> & stamps, std::vector<Query> & queries) {
	std::string input_line;
	// pomocnicze wyrazenia regularne
	std::string stamp_name_regex = "[\\w\\s.-]*";
	std::string post_name_regex = "(([A-Za-z]*\\.?)*\\s+)*([A-Za-z]*\\.?)*";
	std::string value_regex = "((\\d+[.,]\\d+)|([1-9]\\d*))";
	std::string year_regex = "[1-9]\\d{3}";
	boost::regex query_expr {"^\\s*" + year_regex + "\\s+" + year_regex + "\\s*"};
	boost::regex stamp_expr {"^\\s*" + stamp_name_regex + "\\s+" + value_regex +
	                         "\\s+" + year_regex + "\\s+" + post_name_regex + "\\s*"};
	// zmienna sprawdzajaca, czy zaczelismy juz wczytywac zapytania dotyczace lat
	bool start_of_queries = false;

	int line_number = 1;
	while (getline(std::cin, input_line)) {
		if(start_of_queries) {
			if(!boost::regex_match(input_line, query_expr))
				print_error(line_number, input_line);
			else {
				// przetworz zapytanie
			}
		}
		else {
			if(boost::regex_match(input_line, stamp_expr)){
				// przetworz dane o znaczku
			}
			else if(boost::regex_match(input_line, query_expr)) {
				// przetworz zapytanie
				if(true) // jezeli rok1 >= rok2... to bylo to poprawne zapytanie
					start_of_queries = true;
			}
		}
		
	}
}