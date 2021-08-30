public enum Month {

    January(1,31),
    February(2,28),
    March(3,31),
    April(4,30),
    May(5,31),
    June(6,30),
    July(7,31),
    August(8,31),
    September(9,30),
    October(10,31),
    November(11,30),
    December(12,31);

    private int value;
    private int length;
    
    Month(int value, int length) {
        this.value = value;
        this.length = length;
    }

    public int getValue() {
        return value;
    }
    public int getLength() {
        return length;
    }
    
}