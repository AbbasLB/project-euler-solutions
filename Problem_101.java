import java.math.BigDecimal;
import java.util.ArrayList;

public class Newton {

	static BigDecimal power(BigDecimal n, int e) {
		BigDecimal res = BigDecimal.valueOf(1);
		for (int i = 0; i < e; i++)
			res = res.multiply(n);
		return res;
	}

	static BigDecimal f(BigDecimal n) {
		return BigDecimal.valueOf(1).subtract(n).add(power(n, 2)).subtract(power(n, 3)).add(power(n, 4))
				.subtract(power(n, 5)).add(power(n, 6)).subtract(power(n, 7)).add(power(n, 8)).subtract(power(n, 9))
				.add(power(n, 10));
	}

	static BigDecimal testF(BigDecimal n) {
		return n.multiply(n).multiply(n);
	}

	static BigDecimal multMinus(BigDecimal x, BigDecimal rep) {
		BigDecimal res = BigDecimal.valueOf(1);
		for (BigDecimal i = BigDecimal.valueOf(1); i.compareTo(rep) <= 0; i = i.add(BigDecimal.valueOf(1))) {
			res = res.multiply(x.subtract(i));
		}

		return res;
	}

	static BigDecimal calcFIT(ArrayList<BigDecimal> coef, BigDecimal x) {
		BigDecimal res = BigDecimal.valueOf(0);
		for (int i = 0; i < coef.size(); i++)
			res = res.add(coef.get(i).multiply(multMinus(x, BigDecimal.valueOf(i))));
		return res;
	}

	static BigDecimal add_and_retrunFIT(ArrayList<BigDecimal> coef, BigDecimal x, BigDecimal y) {
		BigDecimal newC = y;
		for (int i = 0; i < coef.size(); i++)
			newC = newC.subtract(coef.get(i).multiply(multMinus(x, BigDecimal.valueOf(i))));
		newC = newC.divide(multMinus(x, BigDecimal.valueOf(coef.size())));
		coef.add(newC);
		return calcFIT(coef, x.add(BigDecimal.valueOf(1)));
	}

	static BigDecimal solve() {
		ArrayList<BigDecimal> coef = new ArrayList<BigDecimal>();
		BigDecimal res = BigDecimal.valueOf(0), tmp;
		for (int i = 1; i <= 10; i++) {
			tmp = add_and_retrunFIT(coef, BigDecimal.valueOf(i), f(BigDecimal.valueOf(i)));
			res = res.add(tmp);
			System.out.println("FIT: " + tmp);
			System.out.println("Correct: " + f(BigDecimal.valueOf(i + 1)));
			System.out.println();
		}
		for (int i = 0; i < coef.size(); i++)
			System.out.print(coef.get(i) + " ");
		System.out.println();
		System.out.println("finished");
		return res;
	}

	public static void main(String[] args) {
		System.out.println(solve());
	}

}
