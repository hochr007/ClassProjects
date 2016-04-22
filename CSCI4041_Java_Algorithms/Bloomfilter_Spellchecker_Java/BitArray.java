package project1;

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
