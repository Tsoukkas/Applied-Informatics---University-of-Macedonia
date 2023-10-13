package com.example.a2022_septemvris_champions;

public class Clubs {
    private String name;
    private String year,image;
    public Clubs(String a,String b,String c){
        this.name = a;
        this.year = b;
        this.image = c;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getYear() {
        return year;
    }

    public void setYear(String year) {
        this.year = year;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }
}
