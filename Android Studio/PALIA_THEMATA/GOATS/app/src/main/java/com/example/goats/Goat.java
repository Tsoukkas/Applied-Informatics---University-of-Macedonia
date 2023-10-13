package com.example.goats;

public class Goat {
    String name;
    int tr;
    int totalGA;
    String image;

    public Goat(String a,int b,int c,String d){
          this.name = a;
          this.tr = b;
          this.totalGA = c;
          this.image = d;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getTr() {
        return tr;
    }

    public void setTr(int tr) {
        this.tr = tr;
    }

    public int getTotalGA() {
        return totalGA;
    }

    public void setTotalGA(int totalGA) {
        this.totalGA = totalGA;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }
}
