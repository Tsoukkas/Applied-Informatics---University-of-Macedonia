package com.example.footballselection;


public class Player {
    String name;
    String image;
    String type;
    public Player(String a,String b,String c){
        this.name =a;
        this.image =b;
        this.type=c;
    }

    public String gettype() {
        return type;
    }

    public void setClass(String type) {
        this.type = type;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }
}
