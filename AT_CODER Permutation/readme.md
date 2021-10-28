Đây lại là 1 bài khá hay nữa. Tóm tắt đề: Cho xâu con S độ dài N-1 gồm 2 kí tự '>' và '<' Tìm hoán vị của N số tự nhiên đầu tiên thỏa:
Nếu Si = '<' thì Pi '<' P+1
Và ngược lại

Giải 
Với mỗi 1 Si bất kì, ta sẽ được hoán vị của i+1 số nguyên đầu tiền có dáng P1P2,..,Pi,pi+1
Các hoán vị này lấy từ tập B = {1,2,...,j,...,i,i+1} vậy chúng ta có thể thấy để ghép 1 số nguyên n thuộc tập B trên ta sẽ phải để ý đến con dấu cuối cùng nằm trước nó. Nếu con dấu là '<' chúng ta sẽ phải lấy các phần tử thuộc B0=[1;n) còn nếu con dấu là '>' chúng ta sẽ phải lấy phần tử thuộc B1=(n;i+1). Từ đó chúng ta sẽ có được công thức truy hồi sau:
f(i,j) = sigma(f(i,k)) với k thuộc tập B0 hoặc B1 tùy vào giá trị của con dấu.
Đến đây sẽ nảy sinh 1 vấn đề, giả dụ bạn cần hoán vị của 5 phần tử đầu và phần tử cuối sẽ là 2 với dãy S = '<><>', vấn đề sẽ là các hoán vị có độ dài i-1 đằng trước làm đ gì có số 5 nó chỉ có số 4 thôi nên sẽ bị amogus.
Các hoán vị có kết thúc > 2 ở phía trước là:
1324
1423
2413
Trong khi đó thứ chúng ta cần tìm là:
1435
1534
và ... nhưng t lười liệt kê.

Nhưng có 1 thứ chúng ta cần phải để ý, đó là chúng ta hoàn toàn chỉ quan tâm đến tính thứ tự của chúng
chứ đ quan tâm đến giá trị của chúng nên với tập B chúng ta sẽ cải lùi các phần tử lớn hơn j đi 1 đơn vị rồi đếm.
Như là 1435 nếu cải lùi đi 1 đơn vị nó sẽ trở thành 1324 thuộc tập bên trên. Và đó chính là giải pháp cho vấn đề: cải lùi các phần tử lớn hơn j trong tập B đi 1 đơn vị