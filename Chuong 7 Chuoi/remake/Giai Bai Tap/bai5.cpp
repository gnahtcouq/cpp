
/*
Xuất các từ trên các dòng liên tiếp nhau
vd: "  Nguyen   Viet    Nam   Son  "

Output:
Nguyen
Viet
Nam
Son

Ý Tưởng:
Ta viết ra 1 hàm cắt ra 1 chuỗi con trong
1 chuỗi cho trước với 2 tham số truyền
vào là vị trí bắt đầu cắt và vị trí kết
thúc cắt
vd: SubStr(2, 5); // Cắt đoạn [2, 5]

Start: Duyệt chuỗi gặp ký tự khác khoảng
trắng đầu tiên

End: Từ vị trí Start đó duyệt tiếp, gặp
ký tự khoảng trắng thì lùi về trước đó
1 chỉ số thì đó chính là End

*/