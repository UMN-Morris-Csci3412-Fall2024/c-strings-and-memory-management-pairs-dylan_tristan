#include <gtest/gtest.h>

#include "palindrome.h"

void is_palindrome(char const *str) {
  char const *result = palindrome(str);
  ASSERT_STREQ(result, "Yes");
  free((void*)result);
}

void not_palindrome(char const *str) {
  char const *result = palindrome(str);
  ASSERT_STREQ(result, "No");
  free((void*)result);
}

TEST(Palindrome, HandlesEmptyString) {
  is_palindrome("");
}

TEST(Palindrome, HandlesSingletons) {
  is_palindrome("a");
  is_palindrome("b");
  is_palindrome("c");
}

TEST(Palindrome, HandlesLengthTwo) {
  is_palindrome("aa");
  is_palindrome("bb");
  not_palindrome("ab");
}

TEST(Palindrome, HandlesLengthThree) {
  is_palindrome("aaa");
  is_palindrome("bab");
  not_palindrome("abc");
  not_palindrome("abb");
}

TEST(Palindrome, HandlesLengthFour) {
  is_palindrome("aaaa");
  is_palindrome("baab");
  not_palindrome("abcd");
  not_palindrome("aabb");
  not_palindrome("abbc");
  not_palindrome("abca");
}

TEST(Palindrome, HandlesLongerStrings) {
  is_palindrome("aaaaaaaaaaa");
  is_palindrome("aaaaaaaaaaaa");
  is_palindrome("abcdefgfedcba");
  is_palindrome("abcdefggfedcba");
  not_palindrome("abcdefghijk");
  not_palindrome("aaaaaaaaaaaabaaaa");
  not_palindrome("abcdxfgfedcba");
  not_palindrome("abcdefggfexcba");
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
