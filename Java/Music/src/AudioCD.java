
public class AudioCD {
    private String  title;
    private int playingTime;
    private boolean gotIt;
    private String artist;
    private int numberofTracks;
    private String comment;
    
    public AudioCD(String t, int pT,String A,int nT) {
    	this.title = t;
    	this.playingTime = pT;
    	this.gotIt = false;
    	this.artist = A;
    	this.numberofTracks = nT;
    	this.comment = "no comment";
    }
    
    public void BiggestPT (AudioCD a) {
    	if(this.playingTime > a.playingTime) {
    		System.out.println(this.title);
    	}
    	else {
    		System.out.println(a.title);
    	}
    }
    
    public void SmallestNOT(AudioCD b) {
    	if(this.numberofTracks > b.playingTime) {
    		System.out.println(b.title);
    	}
    	else {
    		System.out.println(this.title);
    	}
    }
    
    public void setGotIt(boolean a) {
    	this.gotIt = a;
    }
    
   
    
    public void setComment(String comment) {
    	this.comment = comment ;
    }
    
    public void setOwnership(boolean a) {
    	this.gotIt = a;
    }

	public boolean isGotIt() {
		return gotIt;
	}

	public String getComment() {
		return comment;
	}
    
    public void print() {
    	System.out.println("CD: " + this.artist + " " + this.title);
    	if(this.gotIt == true) {
    		System.out.print("*");
    	}
    	System.out.println(this.playingTime + "minutes");
    	System.out.println("tracks: " + this.numberofTracks);
    }
}
