#include <gtest/gtest.h>
#include <Automaton.h>

TEST(manual_tests, test1) {
  size_t v = 5;
  size_t start = 0;
  vector<Edge> edges = {{0, 1, "a"},
                        {0, 2, ""},
                        {2, 1, "aba"},
                        {2, 3, "ab"},
                        {3, 4, "a"},
                        {3, 1, "a"},
                        {1, 4, ""},
                        {2, 2, ""},
                        {3, 3, "b"},
                        {4, 2, ""}};
  vector<size_t> finish = {1};
  Automaton a(v, edges, start, finish);
  Automaton b(a);
  a.minimize();
  //ASSERT_EQ(Automaton::IsSameRandom(a, b), true);
}