bool is_lucky(int k) {
  if (k <= 0) { // Lucky numbers are positive integers
    return false;
  }
  int temp_k = k;
  while (temp_k > 0) {
    int digit = temp_k % 10;
    if (digit != 4 && digit != 7) {
      return false; // Found a non-lucky digit
    }
    temp_k /= 10;
  }
  return true; // All digits were 4 or 7
}
int main() {}
