package project1;

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
