#include <iostream>
#include <cstdint>
#include <cstring>

void karatsuba(int* a, int* b, int* c, int n) {
	if (n <= 64) {
		for (int i = 0; i < n; i++)
		       for (int j = 0; j < n; j++)
		       		c[i+j] += a[i] * b[j];	       
	}
	else {
		int k = n / 2;
		int l[k], r[k], t[n] = {0};

		for (int i = 0; i < k; i++) {
			l[i] = a[i] + a[k + i];
			r[i] = b[i] + b[k + i];
		}
		karatsuba(l, r, t, k);
		karatsuba(a, b, c, k);
		karatsuba(a + k, b + k, c + n, k);

		int* t1 = t, *t2 = t + k;
		int* s1 = c, *s2 = c + k, *s3 = c + 2 * k, *s4 = c + 3 * k;

		for (int i = 0; i < k; i++) {
			int c1 = s2[i] + t1[i] - s1[i] - s3[i];
			int c2 = s3[i] + t2[i] - s2[i] - s4[i];
			c[k + i] = c1;
			c[n + i] = c2;
		}
	
	}

}

const int maxn = (1<<20);
int a[maxn], res[maxn];

void mul(int *x, int *y, int n) {
    int tx[n], ty[n];
    std::memcpy(tx, x, sizeof tx);
    std::memcpy(ty, y, sizeof ty);
    std::memset(x, 0, sizeof tx);
    karatsuba(tx, ty, x, n);
}

int main() {

	int* a = new int(111111);
	int * b = new int(3);

	int * res;
	karatsuba(a, b, res, 64);

	std::cout << static_cast<unsigned int>(*res) << std::endl;

//	int k = 64;
//	res[0] = 1;
 //   int len = 1024;
//    while (k > 1) {
//        if (k & 1)
//            mul(res, a, len);
//        mul(a, a, len);
//        k /= 2;
//        len *= 2;
//    }
//    mul(res, a, len);
	
//    std::cout << *res << std::endl;
	return 0;

}
