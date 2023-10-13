package com.example.a2022_animals;

public class Animal {
    String name = "";
    String type = "";
    String voice = "";
    String img = "";

    public Animal(String a,String b,String c,String d){
        this.name =a;
        this.type = b;
        this.voice = c;
        this.img = d;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getVoice() {
        return voice;
    }

    public void setVoice(String voice) {
        this.voice = voice;
    }

    public String getImg() {
        return img;
    }

    public void setImg(String img) {
        this.img = img;
    }
}
