//Andreas Hochrein
//ID: 4855928
//hochr007

//The LineReader used in the Driver.class is the class provided by Prof. Moen

//BitArray

public class BitArray {

	public BitArray(int M){
		if (M<0){
			throw new IllegalArgumentException();
		}
		else{
			m_bitArr_size=M;
			m_intArr_size=(M/32)+1;
			m_bitArr = new int[m_intArr_size];
			for (int i=0; i<m_intArr_size;i++)
				m_bitArr[i]=0;
		}
	}
	//members
	private int m_intArr_size;
	private int m_bitArr[];
	private int m_bitArr_size;
	
	//methods
	public boolean get(int n){
		int a =1;
		a = a << (n%32);
		
		if(n<0 || n>=m_bitArr_size){
			throw new IndexOutOfBoundsException();
		}
		else{
			if ((m_bitArr[n/32]&a)==0)
				return false;
			else
				return true;
		}
	}
	
	public void set(int n){
		int a =1;
		a = a << (n%32);
		
		if(n<0 || n>=m_bitArr_size){
			throw new IndexOutOfBoundsException();
		}
		else{
			m_bitArr[n/32]=m_bitArr[n/32]|a;
		}
	}
	
	public int bitSize(){
		return m_bitArr_size;
	}
}

//Bloomfilter

import java.lang.Math;

public class BloomFilter {
	
	private static final int NUM_HASH_FUNCTIONS = 5; 
	
	public BloomFilter(int M){
		if (M<0)
			throw new IllegalArgumentException();
		else{
			a = new BitArray(M);
			wordSetSize=0;
		}
	}
	
	//members
	private BitArray a;
	private int wordSetSize;
	
	//hash functions
	private int h1(String w){
		return Math.abs(w.hashCode() % (a.bitSize()-1));
	}
	private int h2(String w){
		int h=0;
		for(int i=0;i<w.length();i++)
			h=16*h+w.charAt(i);
		return Math.abs(h % (a.bitSize()-1));
	}
	private int h3(String w){
		int h=0;
		for(int i=0;i<w.length();i++)
			h=(1+i)*w.charAt(i);
		return Math.abs(h% (a.bitSize()-1));
	}
	private int h4(String w){
		int h=0;
		for(int i=0;i<w.length();i++)
			h=i+w.charAt(i);
		return Math.abs(h% (a.bitSize()-1));
	}
	
	private int h5(String w){
		int h=0;
		for(int i=0;i<w.length();i++)
			h=(1+h)*w.charAt(i);
		return Math.abs(h% (a.bitSize()-1));
	}

	//methods
	public void add(String w){
		a.set(h1(w));
		a.set(h2(w));
		a.set(h3(w));
		a.set(h4(w));
		a.set(h5(w));
		wordSetSize++;
	}
	
	public boolean isIn(String w){
		if(a.get(h1(w))&&a.get(h2(w))&&a.get(h3(w))&&a.get(h4(w))&&a.get(h5(w)))
			return true;
		else
			return false;	
	}
	
	public double accuracy(){
		double p= Math.pow((1-(1/Math.exp((NUM_HASH_FUNCTIONS*wordSetSize)/a.bitSize()))),NUM_HASH_FUNCTIONS);
		return p;
	}
}

// Driver

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

//Output printed by Driver: 
//0.1009251902748613