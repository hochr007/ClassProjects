package project1;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int m1 = 4099; //a prime number roughly halfway between 2^12 and 2^13
		BloomFilter bf = new BloomFilter(m1);
		LineReader lreader = new LineReader("basic.txt");
		
		//Read in file and save words in BloomFilter
		while (lreader.hasNext())
			bf.add(lreader.next());
		
		//Check BloomFilter for words and print words that are not stored
		while (lreader.hasNext()){
			String w = lreader.next();
			if(!bf.isIn(w))
				System.out.println(w);
		}
		System.out.println(bf.accuracy());
	}

}
