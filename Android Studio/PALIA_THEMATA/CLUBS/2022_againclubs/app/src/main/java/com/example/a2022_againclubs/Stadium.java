package com.example.a2022_againclubs;

public class Stadium {
    String club;
    String name;
    String fan_chant;
    String image;

    public Stadium(String a,String b,String c,String d){
        this.club = a;
        this.name = b;
        this.fan_chant = c;
        this.image = d;
    }

    public String getClub() {
        return club;
    }

    public void setClub(String club) {
        this.club = club;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getFan_chant() {
        return fan_chant;
    }

    public void setFan_chant(String fan_chant) {
        this.fan_chant = fan_chant;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }
}
