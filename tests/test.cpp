#include <iostream>
#include "strui.hpp"

static size_t passed = 0;
static size_t failed = 0;
static std::string red = "\033[31m";
static std::string green = "\033[32m";
static std::string orange = "\033[38;5;208m";
static std::string reset = "\033[0m";

template <typename T>
static int test(const std::string& name, const T& output, const T& expected);
static void print_start();
static void run_tests();
static void print_results();

int main() {

    print_start();
    run_tests();
    print_results();

    return failed;
}

template <typename T>
static int test(const std::string& name, const T& output, const T& expected)
{
    if (output == expected)
    {
        std::cout << green << "✔ " << name << reset << "\n";
        ++passed;
        return 0;
    }
    else
    {
        std::cerr << red << "⤬ " << name << reset << "\n";
        std::cerr << orange << "    expected → '" << expected << reset << "'\n";
        std::cerr << orange << "    got      → '" << output << reset << "'\n";
        ++failed;
        return 1;
    }
}

static void print_start()
{
    std::cout << "\n";
    std::cout << "----------------\n";
    std::cout << "STRUI LIB TESTS\n";
    std::cout << "----------------\n";
}

static void run_tests()
{
    test(std::string("repeat()"), strui::repeat(3, "ABC", "-"), std::string("ABC-ABC-ABC"));

    std::string input = red + "1\n1234\n12" + reset;
    test(std::string("clean()"), strui::clean(input), std::string("1\n1234\n12"));
    test(std::string("flat_width()"), strui::flat_width(input), size_t(7));
    test(std::string("width()"), strui::width(input), size_t(4));
    test(std::string("height()"), strui::height(input), size_t(3));
    test(std::string("count()"), strui::count("\n", input), size_t(2));

    std::vector<std::string> split_output = strui::split("ABC-ABC-ABC", "-");
    std::vector<std::string> list_input;
    for (int i = 0; i < 3; i++)
    {
        list_input.push_back("ABC");
        std::string test_name = "split() [ " + std::to_string(i + 1) + " / 3 ]";
        test(test_name, split_output[i], std::string("ABC"));
    }
    test(std::string("join()"), strui::join(list_input, "-"), std::string("ABC-ABC-ABC"));

}

static void print_results()
{
    std::cout << "----------------\n";
    std::cout << green << "✔" << reset << " PASSED  → " << passed << "\n";
    std::cout << red << "⤬" << reset << " FAILED  → " << failed << "\n";
    std::cout << (failed == 0 ? green : red) << "----------------" << reset << "\n";
    std::cout << (failed == 0 ? green + "✅ ALL PASSED" : red + "❌ SOME FAILED") << reset << "\n";
    std::cout << (failed == 0 ? green : red) << "----------------" << reset << "\n";
    std::cout << "\n";
}

