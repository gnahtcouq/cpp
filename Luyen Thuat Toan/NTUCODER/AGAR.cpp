#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
  long long n, a, g;
  cin >> n >> a >> g;
  map<long long, vector<int>> m;
  for (int i = 1; i <= n; ++i) {
    long long x;
    cin >> x;
    m[x].push_back(i);
  }
  vector<int> res;
  while (a <= g && !m.empty()) {
    auto it = m.lower_bound(a);
    if (it != m.begin()) {
      it--;
      if ((int)it->second.size() > 0) {
        a += it->first;
        res.push_back(it->second[(int)it->second.size() - 1]);
        it->second.pop_back();
        if ((int)it->second.size() == 0)
          m.erase(it);
      }
    }
    else
      break;
  }
  if (a <= g)
    cout << -1;
  else {
    cout << res.size();
    if ((int)res.size() > 0) {
      cout << endl;
      for (int i = 0; i < (int)res.size(); ++i)
        cout << res[i] << " ";
    }
  }

  return 0;
}

/*

Thì đọc vào yêu cầu đề bài là dễ dàng nhìn ra được tư tưởng giải thuật để giải quyết bài này. Bài này dùng giải thuật tham lam (Greedy Algorithms) để giải quyết. Kể cả bạn nào có không biết về giải thuật tham lam này thì thực ra đôi khi các bạn đang giải quyết vấn đề theo chính tư tưởng của tham lam mà các bạn không biết. Cho bạn nào không biết thì mình có thể nói nhanh như thế này: Tham lam ở đây nghĩa là ta sẽ cố gắng chọn ra cách giải quyết tốt nhất trong tất cả các cách ở hiện tại rồi đi theo cách giải quyết tốt nhất đó nếu lại đứng trước nhiều lựa chọn cách giải quyết khác nhau nữa thì ta lại cố gắng chọn theo cách giải quyết tốt nhất trong số đó tóm lại cứ tốt nhất mà triển vì thế tên gọi nó là tham lam. Quy luật nó là như vậy thôi chứ còn lại không có công thức từng bước cụ thể giải quyết như mấy thuật toán khác. Mà ta có thể giải quyết theo cách bất kỳ miễn cái tư tưởng mà ta giải quyết luôn là chọn theo hướng tốt nhất trong các lựa chọn thì đó chính là tư tưởng của tham lam. Thì tại sao bài này lại có thể nhìn ra tư tưởng của nó là tham lam? Đọc đề bài là thấy rõ mùi rồi hehe muốn xử lý theo quy luật gì gì đó để sau cùng đáp án phải là nhỏ nhất/lớn nhất các kiểu, đọc kiểu này phát thấy mùi tham lam ngay Cụ thể ở bài này là muốn thắng nhưng số người bạn cần phải ăn phải làm sao ít nhất có thể.
Thì thực ra tham lam chỉ là dạng tư tưởng thôi, còn lại để hiện thực được nó thì có thể cần đến những kỹ thuật bổ trợ khác nữa. Mình lấy ví dụ ngay trong chính bài tập này để các bạn thấy rõ.
Đầu tiên kiểm tra nếu kích thước của Ares đã lớn hơn kích thước của Theghost thì ta chẳng cần phải xử lý gì cả, đáp án chỉ in ra 0 thôi. Còn nếu kích thước của Ares bé hơn kích thước của Theghost thì lúc này Ares cần phải tìm ăn các người bạn của mình để tăng kích thước lên đến khi nào vượt qua được Theghost thì dừng lại hoặc khi không còn ăn được người bạn nào nữa thì dừng lại, tùy điều kiện nào xảy ra trước.
Thì với kích thước hiện tại của Ares là A thì chỉ có thể ăn được những người bạn có kích thước < A chứ nếu với kích thước >= A thì Ares sẽ không thể ăn được. Thì để làm sao có thể ăn ít người bạn nhất có thể nhưng phải làm sao để Ares > Theghost. Thì dễ dàng nhìn ra được Ares cần phải ăn người bạn có kích thước lớn nhất mà nhỏ hơn kích thước của Ares hiện tại (để Ares có thể ăn được). Để ăn ít nhất thì phải ăn thằng lớn nhất có thể ăn, quy luật đơn giản là vậy thôi. Rồi sau khi ăn xong lại đi kiểm tra xem kích thước mới của Ares sau khi ăn có > Theghost chưa? Nếu chưa thì lại tiếp tục tìm người bạn có kích thước lớn nhất mà Ares hiện tại có thể ăn và cứ thế lặp lại quy trình trên đến khi nào Ares > Theghost hoặc khi không còn người bạn nào có thể ăn được nữa thì lúc đó dừng chương trình. Lúc này kiểm tra và in kết quả nếu Ares vẫn nhỏ hơn Theghost thì in ra -1, nếu Ares lớn hơn Theghost thì in ra số lượng và vị trí cụ thể của từng người bạn mà Ares đã ăn. Nếu vậy thì ta cần có 1 mảng lưu lại vị trí của từng người bạn mỗi lần Ares ăn để sau cùng đây xuất ra số lượng phần tử mảng chứa và chi tiết từng phần tử của mảng chính là vị trí từng người bạn bị Ares ăn.
Nói vui một chút, tư tưởng tham lam ở trên làm mình nhớ lại ngày xưa mình và ông anh cùng gom tiền nhau mua hộp kem 2 đứa ăn chung. Mỗi đứa tuần tự xúc 1 muỗng. Khi còn gần nửa hộp ổng mới nói thôi để tao ăn 1 miếng cuối cùng rồi cho mày hết. Mình vui vẻ đưa ổng, thế là ổng xúc 1 muỗng cuối gần như vét cạn hết phần kem còn lại trong hộp, đó là quả lừa mình bị ăn, và rõ ràng đó chính là tư tưởng tham lam khi chỉ cần 1 muỗng nhưng xúc nhiều nhất có thể xúc Cũng như bài ở trên, chọn ăn là chọn ăn thằng lớn nhất có thể ăn và cứ thế thì đảm bảo số lượng những đứa bị ăn sẽ là ít nhất rồi. Vì ăn 1 thằng kích thước 10 cũng tương tự ăn 10 thằng kích thước 1 nhưng ăn 1 thằng kích thước 10 thì sẽ đảm bảo số lượng ăn chỉ là 1 và ít nhất có thể đúng như đề bài cần.
Rồi thì nếu đã nhìn ra tư tưởng giải quyết bài như mình đã nói ở trên là coi như đã thành công 50%, 50% còn lại là ở việc có cài đặt đúng được như tư tưởng đã nhìn ra không? 
Thì ở đây ta thấy để chọn được thằng có kích thước lớn nhất có thể mà Ares có thể ăn được, rõ ràng ta cần đi sắp xếp danh sách kích thước của các người bạn tăng dần, rồi thì áp dụng tìm kiếm nhị phân lower_bound để tìm ra thằng đầu tiên thỏa >= kích thước Ares hiện tại. Giả sử lower_bound trả ra kết quả tại vị trí i thì ta hiểu rằng Ares có thể ăn được thằng ở vị trí i - 1 (vì thằng ở vị trí i - 1 có kích thước < Ares hiện tại) chứ thằng ở vị trí i là kích thước >= Ares thì Ares không thể ăn được, quy luật của bài này đã nói rõ chỉ ăn được thằng có kích thước nhỏ hơn thôi.
Hàm lower_bound rất tiện dụng trong tình huống này như đã phân tích ở trên, nếu bạn nào chưa biết cách sử dụng hàm này thì có thể Google search tìm hiểu thêm nhé.
Tóm lại quy trình là:
Bước 1: Ta đi sắp xếp danh sách kích thước những người bạn của Ares tăng dần, chỗ này phải dùng những thuật toán sắp xếp tối ưu với độ phức tạp O(N * logN) chứ N đề bài cho tối đa có thể lên đến 10^5 nên nếu dùng những thuật toán không tối ưu như Interchange Sort, Bubble Sort, Selection Sort … với độ phức tạp O(N^2) thì sẽ bị TLE ngay vì 10^5^2 = 10^10 thì đã vượt quá ngưỡng giới hạn 1 giây là (3 đến 5)*10^7 hay cao lắm là 10^8. Nên phải dùng những thuật toán sắp xếp tối ưu hoặc đơn giản là dùng hàm sort trong STL C++ có sẵn luôn được đảm bảo độ phức tạp là O(N * logN).
Bước 2: Tạo vòng lặp với điều kiện lặp là kích thước của Ares nhỏ hơn Theghost đồng thời Ares còn có thể ăn được. Nếu thoả mãn thì bên trong vòng lặp xử lý tìm kiếm lower_bound trên danh sách kích thước các người bạn đã được sắp xếp ở bước 1, kết quả lower_bound trả về vị trí i thì ta sẽ xử lý cho Ares ăn người bạn ở vị trí i - 1. Lưu trữ vị trí i - 1 vào mảng đáp án res và cứ thế lặp lại quy trình trên đến khi nào vòng lặp không lặp được nữa.
Phần điều kiện lặp làm sao để biết được Ares không thể ăn được thêm người bạn nào? Thì kết quả vị trí i được trả ra từ hàm lower_bound nghĩa là vị trí i đó là phần tử đầu tiên có kích thước >= Ares hiện tại. Ta phải tính đến tình huống nếu i là vị trí đầu mảng, như thế thì chẳng còn phần tử nào trước đó nữa vì thế đây là dấu hiệu cho thấy Ares sẽ không ăn được ai nữa vì ngay phần tử đầu mảng đã >= Ares rồi thì càng tiếp tục về sau vẫn càng >= Ares thôi và Ares sẽ chẳng ăn ai được.
Một vấn đề lưu ý là với những người bạn đã được Ares ăn thì những người đó phải xoá đi khỏi danh sách hay làm cách nào đó để không làm ảnh hưởng đến kết quả tìm kiếm lower_bound lần tiếp theo. Ở đây nếu dùng đến giải pháp xoá trên mảng thì như mình đã từng nói ở 1 số bài đăng, kinh nghiệm nếu có thể tránh được thì nên tránh bởi xoá trên mảng thì toàn bộ các phần tử đằng sau vị trí xoá đó sẽ phải đồng loạt nhích lên, như thế trong trường hợp xấu nhất có thể lên đến O(N) cho 1 thao tác xoá với N là số lượng phần tử của mảng.
Một vấn đề hơi rối của bài này nữa là ở việc đáp án nếu có thể tìm ra cách để Ares ăn được Theghost thì in ra vị trí những người bạn mà Ares ăn và vị trí những người bạn này là dựa theo vị trí ban đầu của họ trong input chứ không phải vị trí sau khi đã được sắp xếp. Vậy nên ta cũng phải tìm cách lưu trữ lại vị trí ban đầu này trước khi sắp xếp để còn có thể lấy ra được vị trí khi cần.
Bước 3: Sau khi vòng lặp ở bước 2 kết thúc thì ta kiểm tra nếu Ares < Theghost thì in ra -1. Ngược lại thì in ra kích thước của mảng res. Nếu kích thước > 0 thì đi in ra từng vị trí cụ thể được lưu trong mảng res.
Nói chung bước phức tạp nhất là bước 2, xử lý tốt bước 2 này là ok. Thì để cho đơn giản mình nên dùng cấu trúc dữ liệu map trong STL C++. Nó được cài đặt theo cơ chế cây đỏ đen (là 1 dạng cây nhị phân tìm kiếm cân bằng). Nếu bạn nào chưa biết về cấu trúc dữ liệu này thì có thể Google search tìm hiểu thêm nhé.
Tại sao nên dùng cấu trúc dữ liệu map? Thì map quản lý các cặp <key, value> và ở đây ta không chỉ lưu trữ kích thước của từng người bạn mà song song đó còn phải lưu trữ theo vị trí của từng người ban đầu nên cặp <key, value> là quá tiện. Rồi mọi thao tác thêm vào hay xoá ra đều là thao tác trên cây cân bằng nên luôn được đảm bảo độ phức tạp O(logN). Do ta cần phải xoá đi khi Ares đã ăn người bạn tương ứng nên dùng cấu trúc map thì thao tác xóa sẽ có độ phức tạp nhỏ hơn mảng rất nhiều. Cái nữa khi dữ liệu được đưa vào map thì phần key sẽ tự động được sắp tăng dần vì cơ chế của cây nhị phân tìm kiếm khi dữ liệu được thêm vào là sẽ tìm vị trí thích hợp để chèn trên cây và luôn đảm bảo độ phức tạp O(N * logN) cũng tương tự như bước sắp xếp mảng dùng hàm sort, nhưng dùng map rồi thì khỏi cần làm bước 1 luôn. Và map cũng hỗ trợ sẵn tính năng lower_bound để tìm kiếm key. Quá nhiều lý do nên dùng cấu trúc dữ liệu map với bài này các bạn thấy không?
Ta sẽ tạo cấu trúc map với key chính là kích thước của từng người bạn, còn value là vị trí của kích thước đó trong danh sách ban đầu. Vì ta cần danh sách kích thước các người bạn tăng dần vì thế phần kích thước phải đưa vào key còn phần vị trí đưa vào value, quá rõ ràng để thấy.
Tuy nhiên có 1 vấn đề này của map đó là với cấu trúc map thì các key không được trùng nhau, nếu nhiều key trùng nhau đưa vào thì nó chỉ lấy theo thằng cuối cùng. Trong khi đó đề không nói là kích thước từng người bạn sẽ phân biệt nhau, nghĩa là sẽ có khả năng bị trùng kích thước nhau. Nếu không lường trước chỗ này thì dùng map sẽ bị sai nhé các bạn. 
Để giải quyết vấn đề key bị trùng nhau như đã nói ở trên thì phần value lưu trữ vị trí ta sẽ không tạo nó ở dạng 1 biến đơn lẻ bình thường mà sẽ cho nó là 1 mảng (trong bài này khi nói đến mảng thì mặc định mình dùng kiểu mảng động vector cho tiện lợi nha các bạn, các bạn nào chưa biết có thể Google search tìm hiểu thêm nhé). Thì cứ mỗi dữ liệu key đưa vào map sẽ tìm kiếm xem nếu nó có trong map rồi thì phần value tương ứng sẽ nạp thêm vị trí của nó vào sau cùng (thêm vào sau cùng thì độ phức tạp chỉ O(1)). Còn nếu key đưa vào là mới hoàn toàn thì map sẽ thêm mới key đó. Rồi ở thao tác tìm kiếm lower_bound khi đã tìm ra vị trí i-1 hợp lệ mà Ares có thể ăn được thì sau khi ăn xong (Ares += key) ta kiểm tra nếu kích thước size vector của value tại key tương ứng mà > 0 thì ta sẽ lưu trữ phần tử tại vị trí [size-1] của vector đó vào mảng res và xóa đi phần tử cuối cùng của vector đi (thao tác xóa phần tử cuối cùng chỉ cần độ phức tạp O(1)). Sau khi xóa xong kiểm tra nếu size còn lại là 0 nghĩa là phần tử key đó đã xét hết, ta sẽ xóa key đó trong map luôn.
Source code cho các bạn tham khảo để thấy rõ những gì mình đã phân tích chi tiết ở trên:
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, a, g;
    cin >> n >> a >> g;
    map<long long, vector<int>> m;
    for(int i = 1; i <= n; ++i){
        long long x;
        cin >> x;
        m[x].push_back(i);
    }
    vector<int> res;
    while(a <= g && !m.empty()){
        auto it = m.lower_bound(a);
        if(it != m.begin()){
            it--;
            if((int)it->second.size() > 0){
                a += it->first;
                res.push_back(it->second[(int)it->second.size() - 1]);
                it->second.pop_back();
                if((int)it->second.size() == 0){
                    m.erase(it);
                }
            }
        }
        else{
            break;
        }
    }
    if(a <= g){
        cout << -1;
    }
    else{
        cout << res.size();
        if((int)res.size() > 0){
            cout << endl;
            for(int i = 0; i < (int)res.size(); ++i){
                cout << res[i] << " ";
            }
        }
    }
    return 0;
}
Giải thích 1 số chỗ trong cách làm ở trên:
1/ Phần key của map mình dùng kiểu dữ liệu long long cho chắc để tránh bị tràn số.
2/ Trong bước đọc dữ liệu từ input thì vòng lặp for i chạy từ 1 tới n, mỗi lần sẽ có biến long long x đọc dữ liệu kích thước của từng người bạn vào biến x đó, rồi ta có dòng lệnh: m[x].push_back(i); nghĩa là key x sẽ được đưa vào map bằng cách để m[x] đây là cách viết gọn thay vì dùng insert. Nó sẽ tìm kiếm key x trong map xem có không? nếu không thì nó sẽ tạo mới trong map còn nếu có thì sẽ dừng lại ngay vị trí tìm thấy, rồi thì tại đó chính là value là kiểu vector thì ta sẽ .push_back(i) để đưa vị trí i đó vào sau cùng của vector.
3/ Trong vòng lặp while mình dùng kiểu auto cho biến it (con trỏ iterator) để tự trình biên dịch xác định kiểu cho biến it đó, từ C++ 11 trở lên thì có hỗ trợ này còn trước đó thì không nên các bạn cũng lưu ý khi chọn phiên bản trình biên dịch lúc nộp bài nhé. Còn nếu không dùng auto mà viết đầy đủ khai báo sẽ là: map<long long, vector<int>>::iterator it
4/ Cũng trong vòng lặp while, kết quả sau khi tìm với lower_bound trên map nếu con trỏ it mà bằng m.begin() tức là phần tử đầu tiên của map thì như mình đã phân tích như thế là chẳng thể tìm được phần tử nào mà Ares có thể ăn được, vậy thì ta break thoát khỏi vòng lặp luôn. Còn khi it != m.begin() tức là sẽ tồn tại phần tử lớn nhất mà Ares ăn được, phần tử đó nằm tại vị trí it-- tức là vị trí liền trước.
5/ Khi đã tìm ra được vị trí it thì it->first chính là key (là kích thước của người bạn) còn it->second chính là value (là vector chứa danh sách vị trí ban đầu trong input của kích thước đó). Vậy nên ta sẽ thấy a += it->first chính là a += key đó. Tiếp theo đó kiểm tra xem size của vector tại value tương ứng với key thì ta gọi ra bằng cách it->second lúc này hiểu it->second chính là vector nhé rồi mọi thao tác như truy cập vị trí index hay gọi các hàm hỗ trợ của nó thì các bạn cứ tưởng tượng ta có: vector<int> v; v.pop_back(); chẳng hàn thì giờ đây thay v là it->second thì ta sẽ là: it->second.pop_back(); tương tự vậy với việc truy cập index hay các phương thức khác, có thể các bạn sẽ bị rối chỗ này nên mình giải thích kỹ.
Đánh giá độ phức tạp của cách làm này:
+ Độ phức tạp không gian (Space Complexity): Nói chung các cấu trúc dữ liệu trong STL hỗ trợ như map hay vector lúc nào nó cũng cho sẵn 1 kích thước dự phòng lớn để dữ liệu cứ thêm vào thoải mái nên ta cũng không nói chính xác được là bao nhiêu. Tuy nhiên nếu xét trong phạm vi ngữ cảnh các dữ liệu mà trong bài đưa vào thì phần map tuy nó chỉ chứa những key phân biệt nhưng với những key trùng nhau thì vị trí sẽ được đưa tiếp thêm vào value tương ứng. Vậy nên map cũng vẫn sẽ lưu trữ đủ N phần tử của danh sách. Và vector res trong trường hợp xấu nhất khi Ares ăn hết tất cả những người bạn của mình thì cũng là N phần tử. Vậy ta có thể kết luận độ phức tạp không gian của code ở trên là O(2 * N).
+ Độ phức tạp thời gian (Time Complexity): Bước đọc dữ liệu từ input vòng lặp chạy N lần, mỗi lần sẽ đưa dữ liệu vào map tốn logN (chưa xét đến chi phí cân bằng cây) nên thôi bước này có thể xem như tổng quát là O(N * logN). Vòng lặp while duyệt xử lý trong trường hợp xấu nhất khi Ares ăn hết N người bạn của mình và mỗi lần sẽ tìm lower_bound sẽ hết logN nên tổng quát bước này sẽ có độ phức tạp O(N * logN). Bước kết luận trong trường hợp xấu nhất mảng res chứa đủ N người bạn thì sẽ lặp hết O(N) lần để in ra. Vậy tổng quát độ phức tạp sẽ là: O(N * logN) + O(N * logN) + O(N) thì theo quy tắc cộng của BigO sẽ lấy theo thành phần lớn nhất nên ta có thể kết luận độ phức tạp thời gian của cách làm này là O(N * logN) với N là số lượng người bạn của Ares.
Thử nhẩm xem với trường hợp xấu nhất khi N là 10^5, thì log(10^5) thì log ở đây cụ thể là logarit cơ số 2, log(10^5) làm tròn coi như là 17. Vậy sẽ là 17 * N + 17 * N + N = 35 * N. Với N là 10^5 thì 35 * 10^5 coi như là 3.5 * 10^6. Thì yên tâm vẫn nằm trong ngưỡng giới hạn tiêu chuẩn 1 giây là (3 đến 5) * 10^7 hay cao lắm là 10^8 nên giới hạn hiện tại chỉ = 1/10 so với ngưỡng tiêu chuẩn, vì thế ngưỡng tiêu chuẩn cho giới hạn 1 giây (1000 ms) thì code ở trên chỉ chạy tầm 100 ms thôi nên yên tâm không sợ bị TLE nhé.

*/