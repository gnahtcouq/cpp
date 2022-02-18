#include <iostream>
#include <string>
using namespace std;
int main() {
  string a[] = { "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEEN" };
  string s;
  getline(cin, s);

  int res = -1;
  for (int i = 0; i < 10; ++i) {
    int idx = 0;
    for (int j = 0; j < (int)s.length(); ++j) {
      if (s[j] == a[i][idx]) {
        idx++;
        if (idx == (int)a[i].length()) {
          res = i;
          i = 10;
          break;
        }
      }
    }
  }
  if (res == -1)
    cout << "CHIA BUON, PHAI VE ROI, HEN NAM SAU NHE!!";
  else
    cout << a[res];

  return 0;
}

/*

Bài này mình được một bạn học viên hỏi nên sẵn tiện mình viết bài giải chi tiết để nhiều bạn được tham khảo luôn. Hy vọng mang đến được giá trị cho các bạn. Các bạn nào muốn thử nộp bài để hệ thống chấm có đúng hay không thì link bài đây nha: https://luyencode.net/problem/PTIT037
Trước khi đi vào vấn đề chính của bài thì mình muốn các bạn phải đảm bảo biết qua điều này để về sau các bạn xem mới hiểu:
Với các hệ thống web chấm bài giới hạn thời gian chạy của bài tối đa chỉ được 1 giây thì các bạn sẽ rất dễ bị rơi vào lỗi Time Limit Exceeded (TLE: Chạy quá giới hạn thời gian cho phép). Thì như mình đã nói rất nhiều lần là với các hệ thống web chấm bài hiện nay nếu không muốn bị TLE thì tối đa số phép toán trên toàn bài của các bạn chỉ nên ở ngưỡng (3 đến 5)*10^7 là ngưỡng an toàn với phần lớn hệ thống chấm bài, hoặc với một số hệ thống chấm server mạnh hơn thì có thể nâng ngưỡng lên 10^8 nhưng cũng hên xui nhé. Và thực ra ta không phải đếm chi tiết từng số phép toán trên toàn bài mà ta dựa theo số lần vòng lặp chạy bởi bên trong vòng lặp là nó xử lý lặp đi lặp lại nhiều phép toán nên cứ canh theo đó, các bạn cứ hiểu là tối đa toàn bài chỉ nên lặp (3 đến 5)*10^7 lần là an toàn hoặc tệ nhất là 10^8 (lúc này thì hên xui nhé) còn vượt ngưỡng này là khả năng TLE rất cao nhe. Lưu ý là ngưỡng mình vừa nói ở trên là với ngôn ngữ C/C++ thôi nhé chứ nếu với những ngôn ngữ khác như Python, C# hay Java nó chạy chậm hơn C/C++ thì ngưỡng đó phải thấp hơn, hoặc người ra đề sẽ chủ động đưa ra giới hạn nếu nộp với C/C++ thì thời gian chạy quy định tối đa 1 giây, các ngôn ngữ khác thì 2 giây. Và ngưỡng mình đưa ra ở trên nếu với đề cho thời gian 2 giây thì các bạn cứ tỷ lệ thuận nhân 2 lên với ngưỡng, 3 giây thì nhân 3, nếu 100 ms tức là 1/10 giây thì các bạn chia 10 cho ngưỡng đó nhé, cứ thế thôi.
Rồi thì với bài này giới hạn thời gian là 1 giây thì cứ như ở trên mình đã phân tích kỹ rồi hen. Giờ ta sẽ thảo luận cách giải quyết bài này.
Bài này phải nói là nên ở mức dễ sẽ đúng hơn là mức trung bình, vì với yêu cầu của đề bài đưa ra cũng như giới hạn độ lớn dữ liệu đầu vào chuỗi chỉ dài tối đa 1000 là quá nhỏ, dù cho cách làm tệ nhất vẫn không sợ bị chạy quá giới hạn thời gian cho phép (tất nhiên nếu cách làm tệ quá mức thì vẫn sẽ bị chạy quá thời gian nhé). Tuy nhiên chưa chắc bạn nào cũng có thể giải quyết theo cách gọn gàng, vì mình đã xem qua code của bạn hỏi bài mình thì thấy bạn code xử lý khá rườm rà phức tạp nên ở đây mình sẽ phân tích hướng dẫn các bạn nào chưa làm được tham khảo qua một cách rất gọn với bài này, các bạn chú ý xem những điều mình chia sẻ dưới đây nha.
Như trường hợp bài này, đề bài định nghĩa ta sẽ chọn ra một số chữ cái trong xâu ban đầu và không được đảo vị trí các chữ cái, nghĩa là thằng nào được chọn trước thì trong xâu ban đầu nó cũng sẽ đứng trước thằng được chọn sau, hay nói rõ hơn là ta chỉ đi từ đầu đến cuối và chọn ra chứ không được đi lùi lại, cứ đi tới thôi. Và cần kiểm tra xem có thể chọn ra được các chữ cái tiếng Anh của các số từ 0 đến 9 hay không? Nếu không thể thì sẽ kết luận chia buồn hẹn năm sau gì gì đó còn nếu chọn được thì ta sẽ ưu tiên chọn sao cho các chữ cái được chọn là số nhỏ nhất (trong các số từ 0 đến 9) và in ra từ tiếng Anh của số đó ra. Đọc đến đây là ta hiểu rằng ta sẽ đi xét lần lượt từ tiếng Anh của các số từ bé nhất trở lên tức là từ 0 trở lên để nếu tìm thấy trường hợp thoả mãn thì ta ngay lập tức dừng lại và in ra kết quả luôn không cần phải xét tiếp từ tiếng Anh của các số tiếp theo vì ta đang đi xét từ số nhỏ đến số lớn, ngay lúc nào thoả thì đó đảm bảo là số nhỏ nhất đúng như yêu cầu của đề bài rồi. Còn trường hợp xấu nhất là khi xét từ tiếng Anh của lần lượt đủ 10 số từ 0 đến 9 mà vẫn không tìm thấy thì lúc này ta kết luận chia buồn. Đơn giản là vậy thôi, nhưng cách cài đặt nếu không biết sẽ code dài dòng phức tạp lắm. Dưới đây mình sẽ hướng dẫn cho các bạn cách code cho đơn giản.
Giờ nói chi tiết cách thức xử lý khi tìm 1 chuỗi con cụ thể nào đó, ví dụ chuỗi con cần tìm là “ZERO” và tìm xem có nằm trong chuỗi gốc ban đầu không? Và chuỗi con ZERO này trong chuỗi gốc không nhất thiết các ký tự nằm liên tiếp nhau mà nó có thể rời rạc cách xa nhau, miễn là đúng theo nguyên tắc vị trí của nó tức là đầu tiên sẽ có ký tự ‘Z’ sau đó đến ký tự ‘E’ rồi ký tự ‘R’ và sau cùng là ký tự ‘O’. Để ta có thể chọn được để ghép được thành “ZERO”. Nếu gặp đủ 4 ký tự theo đúng thứ tự gặp mặt như vậy trong chuỗi gốc ban đầu thì ngay lập tức kết luận tìm thấy và in nó ra, nếu đến cuối cùng mà không tìm thấy thì ta sẽ xét tìm sang chuỗi con tiếp theo là “ONE” rồi nếu tìm thấy thì kết luận nếu không thấy lại xét tiếp sang chuỗi con “TWO” và cứ thế quy trình lặp lại đến khi xét tìm đến chuỗi con “NINE” rồi mà vẫn không thấy thì kết luận chia buồn. Vấn đề lúc này đơn giản là vậy thôi, tức là duyệt xét từng ký tự của chuỗi gốc ban đầu.
Ví dụ giờ cần tìm chuỗi con “ZERO” đi thì rất đơn giản chỉ cần duyệt chuỗi đầu vào, xét tìm thấy ký tự ‘Z’ đầu tiên thì tăng biến đếm lên 1, sau đó tiếp tục duyệt xét thấy ký tự ‘E’ thì tăng biến đếm lên 1, sau đó tiếp tục duyệt xét thấy ký tự ‘R’ thì tăng biến đếm lên 1, sau đó tiếp tục duyệt xét thấy ký tự ‘O’ thì tăng biến đếm lên 1 nữa. Cứ mỗi lần biến đếm được tăng lên 1 thì ta kiểm tra nếu thấy biến đếm là 4 (tức là bằng độ dài chuỗi “ZERO”) thì nghĩa là chuỗi “ZERO” đã xuất hiện đủ trong chuỗi ban đầu theo thứ tự, lúc này ta có thể dừng việc tìm kiếm và kết luận. Còn nếu xét hết chuỗi ban đầu rồi mà biến đếm vẫn chưa bằng được với độ dài chuỗi con mà ta đang tìm kiếm thì nghĩa là chuỗi con đó không tồn tại, ta xét qua chuỗi con tiếp theo (“ONE”) và lặp lại quy trình như trên.
Vậy cách xử lý tổng quát là thế này: Đầu tiên ta tạo luôn mảng chuỗi a (string a[]) có 10 phần tử, với mỗi phần tử trong chuỗi sẽ là từ tiếng Anh từ 0 đến 9. Cụ thể lúc này a[0] = “ZERO”, a[1] = “ONE”, cứ thế đến a[9] = “NINE”. Rồi thì duyệt xét tìm chuỗi con a[i] với i lần lượt từ 0 đến 9 trong chuỗi gốc s ban đầu. Khởi tạo biến số nguyên idx = 0 để ta duyệt lần lượt từng ký tự trong chuỗi con a[i] (tức là xét từng ký tự a[i][idx] với idx từ 0 đến a[i].length() - 1. Ta duyệt xét lần lượt từng ký tự s[j] trong chuỗi s, so sánh nếu nó bằng với ký tự a[i][idx] của chuỗi con a[i] thì ta sẽ tăng biến idx lên 1 (idx++) để lần xét ký tự s[j] tiếp theo nó sẽ xét tìm ký tự tiếp theo của chuỗi con a[i]. Cứ mỗi lần tìm thấy ký tự trùng khớp (s[j] == a[i][idx]) thì ta kiểm tra xem giá trị idx có bằng với độ dài của chuỗi con a[i] đang xét không? Nếu bằng nghĩa là toàn bộ chuỗi con a[i] đã được tìm thấy, ta lưu giá trị index i (index chuỗi con đang xét trong mảng chuỗi a) vào biến res và kết thúc cả 2 vòng lặp rồi sau cùng in ra đáp án chuỗi con nhỏ nhất tìm thấy là a[res]. Biến res lúc này đang ý nghĩa lưu lại index của chuỗi con đầu tiên tìm thấy, ban đầu ta nên khởi tạo biến res = -1 để sau cùng ta kiểm tra nếu res vẫn là -1 thì ta in ra chia buồn, biến res đóng vai trò như cờ hiệu bởi làm gì có index nào là -1 đúng không? còn nếu index khác -1 nghĩa là ta hiểu đã tìm ra được chuỗi con.
Source code các bạn tham khảo để nhìn thấy rõ với tất cả những gì mình đã phân tích ở trên

#include <bits/stdc++.h>
using namespace std;
int main(){
    string a[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    string s;
    getline(cin, s);
    int res = -1;
    for(int i = 0; i < 10; ++i){
        int idx = 0;
        for(int j = 0; j < (int)s.length(); ++j){
            if(s[j] == a[i][idx]){
                idx++;
                if(idx == (int)a[i].length()){
                    res = i;
                    i = 10;
                    break;
                }
            }
        }
    }
    if(res == -1){
        cout << "CHIA BUON, PHAI VE ROI, HEN NAM SAU NHE!!";
    }
    else{
        cout << a[res];
    }
    return 0;
}

Các bạn chú ý kỹ chỗ if(idx == (int)a[i].length()) trong đoạn code ở trên, mình xử lý đầu tiên lưu biến res = i sau đó cập nhật i = 10 rồi thì mới break. Lý do tại sao lại phải cập nhật i = 10? Bởi nếu ta chỉ lưu giá trị res = i xong rồi break ra thì câu lệnh break lúc này nó chỉ giúp ta thoát ra khỏi vòng lặp gần nhất đang chứa nó là vòng lặp for j thôi, và vòng lặp for i thì vẫn còn thế nên đây là mẹo khi ta gán i = 10 thì lúc này khi nó thoát ra khỏi vòng lặp for j thì tiếp tục vòng for i sẽ làm bước lặp i++ (lúc này i đang là 10 thì sẽ tăng lên thành 11) rồi thì kiểm tra điều kiện i < 10 lúc này nó không thoả nên tự kết thúc vòng lặp for i luôn. Sau cùng ra bên ngoài ta kiểm tra biến res và kết luận.
Thì thực ra là do mình quen code kiểu sau cùng mới đi kiểm tra kết luận, chứ thực ra ta có thể ngay lập tức in ra kết luận luôn và return 0; kết thúc chương trình tại đó. Và cuối cùng của hàm main ta để dòng kết luận chia buồn để nếu chương trình vẫn còn chạy được xuống dưới cùng đó tức là nó không bị kết thúc sớm tức là không có tìm thấy bất kỳ chuỗi con nào trong 10 chuỗi con thì lúc này ta in ra câu chia buồn.
Source code các bạn tham khảo để nhìn thấy rõ với tất cả những gì mình đã phân tích ở trên

#include <bits/stdc++.h>
using namespace std;
int main(){
    string a[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    string s;
    getline(cin, s);
    for(int i = 0; i < 10; ++i){
        int idx = 0;
        for(int j = 0; j < (int)s.length(); ++j){
            if(s[j] == a[i][idx]){
                idx++;
                if(idx == (int)a[i].length()){
                    cout << a[i];
                    return 0;
                }
            }
        }
    }
    cout << "CHIA BUON, PHAI VE ROI, HEN NAM SAU NHE!!";
    return 0;
}

Đánh giá độ phức tạp củch làm này: 
+ Độ phức tạp không gian (Space Complexity): O(1) vì mảng chuỗi 10 phần tử thì cũng chỉ là số nhỏ cố định không đáng kể.
+ Độ phức tạp thời gian (Time Complexity): Trong trường hợp xấu nhất là khi không tìm thấy bất kỳ chuỗi con nào, độ phức tạp lúc này là O(10 * N) với N là độ dài chuỗi đầu vào.
Thì ta thấy độ dài chuỗi tối đa 10^3 nên với trường hợp xấu nhất như mình đã nói ở trên thì số lần lặp cũng chỉ là 10 * 10^3 = 10^4 thì nó thoả nhỏ hơn ngưỡng giới hạn 1 giây mà khúc đầu mình có nói là (3 đến 5)*10^7 hay cao lắm là 10^8 nên yên tâm sẽ không sợ bị TLE nhé.
Thực ra nếu muốn tối ưu hơn về độ phức tạp thời gian thì vẫn có cách để trong trường hợp xấu nhất sẽ không phải lặp đủ 10*N (với N là độ dài chuỗi đầu vào). Tuy nhiên nó phải code dài thêm một chút vì thế nếu trong trường hợp bài này khi độ dài chuỗi đầu vào tối đa cũng chỉ 10^3 thì là mình thì mình sẽ chọn cách ngắn gọn đơn giản như ở trên thôi vì nó vẫn đảm bảo không sợ bị TLE. Nhưng nếu giả sử độ dài chuỗi đầu vào tối đa có thể lên đến 10^7 chẳng hạn hay cao hơn nữa như cỡ 5*10^7 thì lúc này cách ở trên sẽ có thể bị TLE. Lúc này ta phải tìm giải pháp tốt hơn một chút để trường hợp xấu nhất là khi không tồn tại bất kỳ chuỗi con nào nó sẽ vẫn nhanh chóng kết luận được mà không phải lặp đủ 10*N lần (với N là độ dài chuỗi đầu vào).
Ý tưởng là ta sẽ sử dụng 2 mảng đánh dấu cntS, cntA mỗi mảng có 26 phần tử để thống kê số lần xuất hiện của tương ứng 26 chữ cái từ A đến Z trong chuỗi đầu vào s và chuỗi con a[i]. Với mảng đánh dấu cntS của chuỗi đầu vào thì ta chỉ thống kê qua 1 lần còn với mảng đánh dấu cntA của chuỗi con a[i] thì có thể nếu phải xét tiếp qua chuỗi con a[i] tiếp theo thì phải đi thống kê lại mảng đánh dấu với chuỗi con a[i] mới.
Thì sau khi ta có được 2 mảng đánh dấu, lúc này khi ta duyệt chuỗi con a[i] khi xét vào từng ký tự của chuỗi con tức là a[i][idx] thì ta đối chiếu nó qua mảng đánh dấu cntA để xem ký tự đó cả thảy trong chuỗi con a[i] xuất hiện bao nhiêu lần? Rồi đồng thời gọi nó qua mảng đánh dấu cntS để xem ký tự đó trong mảng cntS xuất hiện bao nhiêu lần? Nếu số lần xuất hiện của ký tự đó bên mảng cntS mà bé hơn số lần xuất hiện bên mảng cntA thì ta có thể ngay lập tức kết luận sẽ không thể tìm thấy chuỗi con a[i] trong chuỗi s được, lúc này ta xét tiếp qua chuỗi con a[i] tiếp theo mà khỏi cần phải đi vào duyệt qua toàn bộ chuỗi s như cách làm trước rồi mới biết là không tồn tại, lúc này ta có thể biết được ngay. Còn nếu số lần xuất hiện bên mảng cntS của từng ký tự trong chuỗi con a[i] mà luôn thoả >= số lần xuất hiện của ký tự tương ứng đó bên mảng cntA thì lúc này ta duyệt vào chuỗi s và đi tìm kiếm xem liệu có tồn tại chuỗi con a[i] trong chuỗi s không? Cách tìm kiếm tương tự như cách làm trước đó mình đã phân tích, nhưng ta có thể tiếp tục tận dụng mảng đánh dấu để có thể phát hiện ra khi nào nó thực sự không thể tồn tại được mà không cần phải xét đến tận cùng chuỗi s rồi mới biết được, bằng cách mỗi lần xét vào ký tự s[i] so sánh với ký tự a[i][idx] nếu trùng nhau thì ngoài việc tăng biến đếm lên thì ta đồng thời giảm đi 1 đơn vị ở vị trí ký tự tương ứng trong 2 mảng đánh dấu cntS, cntA, còn nếu so sánh ký tự s[i] khác với ký tự a[i][idx] thì lúc này giảm số lần xuất hiện của kýtự s[i] tương ứng trong mảng đánh dấu cntS đi 1 đơn vị (lúc này không giảm bên mảng cntA chỉ giảm mảng cntS thôi nhé). Rồi ta kiểm tra nếu số lần xuất hiện của ký tự s[i] đang xét bên mảng cntS mà nhỏ hơn số lần xuất hiện của ký tự tương ứng đó bên mảng cntA thì ta chắc chắn rằng chuỗi con a[i] không tồn tại trong s, lúc này ta có thể kết thúc để xét qua chuỗi con a[i] mới hoặc nếu trong trường hợp chuỗi con a[i] hiện tại đang là cuối cùng thì ta kết luận chia buồn. 
Source code các bạn tham khảo để nhìn thấy rõ với tất cả những gì mình đã phân tích ở trên

#include <bits/stdc++.h>
using namespace std;
int main(){
    string a[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    string s;
    getline(cin, s);
    int cntS[26];
    int temp_cntS[26] = {0};
    int index;
    for(int i = 0; i < (int)s.length(); ++i){
        index = s[i] - 'A';
        temp_cntS[index]++;
    }
    for(int i = 0; i < 10; ++i){
        for(int k = 0; k < 26; ++k){
            cntS[k] = temp_cntS[k];
        }
        int cntA[26] = {0};
        bool check = true;
        for(int k = 0; k < (int)a[i].length(); ++k){
            index = a[i][k] - 'A';
            cntA[index]++;
            if(cntS[index] < cntA[index]){
                check = false;
                break;
            }
        }
        if(check == true){
            int idx = 0;
            for(int j = 0; j < (int)s.length(); ++j){
                index = s[j] - 'A';
                if(s[j] == a[i][idx]){
                    idx++;
                    if(idx == (int)a[i].length()){
                        cout << a[i];
                        return 0;
                    }
                    cntA[index]--;
                }
                cntS[index]--;
                if(cntS[index] < cntA[index]){
                    break;
                }
            }
        }
    }
    cout << "CHIA BUON, PHAI VE ROI, HEN NAM SAU NHE!!";
    return 0;
}

Lưu ý: Vì trong quá trình duyệt chuỗi s ta có trực tiếp thay đổi cntS[index]-- để so sánh với cntA[index] (ở khúc cuối cùng trong code ở trên) nên mảng đánh dấu cntS đã bị thay đổi khi xét từng chuỗi con a[i] nếu phải tiếp tục xét qua chuỗi con a[i] tiếp theo thì mảng cntS đã không còn chính xác nữa, vì thế ban đầu ta tạo mảng đánh dấu temp_cntS để thống kê số lần xuất hiện các ký tự trong chuỗi s rồi mỗi lần xét chuỗi con a[i] thì ta sẽ gán dữ liệu mảng temp_cntS sang mảng cntS để như reset lại mảng cntS về giá trị ban đầu.
Thì với cách làm này trong trường hợp xấu nhất như cách làm trước đó phải duyệt đủ qua 10 chuỗi con, thực ra mấy chuỗi con đó độ dài chẳng bao nhiêu cả nên chẳng đáng kể nhưng đáng kể là ta phải 10 lần duyệt đi duyệt lại chuỗi s còn với cách làm này ta chỉ luôn chỉ mất 1 lần duyệt qua toàn bộ chuỗi s để tạo mảng đánh dấu nhưng với trường hợp xấu nhất khi không tồn tại chuỗi con nào thoả thì nó cũng chỉ duyệt qua 10 chuỗi con thôi và duyệt thêm qua các mảng đánh dấu nhưng các chuỗi con hay các mảng đánh dấu thì độ dài cũng không đáng kể, đáng kể là độ dài chuỗi s cơ nhưng cách này sẽ không phải duyệt thêm chuỗi s 1 lần nào nữa (thực ra cũng có thể phải duyệt đấy nhưng mà không cần phải luôn duyệt đến tận cùng mà có thể dừng sớm), đây là điểm để ghi nhận nó được tốt hơn cách làm trước đó nhưng đánh đổi lại là phải code dài và phức tạp thêm, nên như mình đã nói nếu độ dài chuỗi đầu vào < 10^7 thì cứ dùng như cách đầu tiên cho đơn giản, chừng nào >= 10^7 lúc đó mình mới phải nặn óc suy nghĩ ra những hướng làm tốt hơn như kiểu thế này

*/