Thực ra đây là 1 bài rất hay, dạng bài lần đầu đương đầu
Tóm tắt đề bài:
Có N cặp nam và nữ, mỗi nam i và nữ j sẽ được đánh giá là hợp khoặc không hợp.
Nếu a[i][j] = 0 => nam i và nữ j không hợp nhau. Ngược lại hợp nhau sẽ là 1.
Cho 1 mảng a[N][N], hỏi có bao nhiêu cách để tất cả nam và nữ đều có cặp.

Example:
3
0 1 1
1 0 1
1 1 1
=>3
Giải thích: Có 3 cách chọn thỏa đề:
(1,2),(2,1),(3,3)
(1,2),(2,3),(3,1)
(1,3),(2,1),(3,2)

Khi mới tiếp cập bài toán, có thể ta sẽ đưa ra hướng tiếp cận là bảng phương án f(i,j) có bao nhiêu cặp thỏa khi xét đến nam i và nữ j nhưng mà đời đéo như là mơ, cách đấy ngu học vl. Khi sử dụng cách này sẽ gặp phải rất nhiều trở ngại vì mỗi lần nam i chọn nữ j thì toàn bộ nhưng nam còn lại không được phép chọn lại cô j, để giải quyết vấn đề này sẽ tốn rất nhiều thời gian, và đây là 1 cách tiếp cận khác, khôn hơn.

Như đã nói ở trên, khi anh i chọn cô j thì không 1 ai nữa được phép chọn cô j, vậy giả sử tập hợp những người phụ nữ có thể chọn có dạng: (1,2,3,...,N). Vậy mỗi khi 1 anh i bất kì chọn 1 cô j thì tập sẽ trở thành: (1,2,3,...,N)\(j).
Từ đó ta có thể viết công thức quy hoạch động cơ bản như sau:
f([1,2,...,N]) = sum(f[1,2,...,N]\(j),1 <= j <= N nếu a[i][j] = 1)
Với cách như trên, ta hoàn toàn có thể dùng cho đệ quy có nhớ trong các ngôn ngữ bậc cao như js hoặc python, nhưng mà với C++ thì sao? Câu trả lời sẽ là chúng ta ép chúng về dãy bit!
Giả dụ ta có 1 dãy các phụ nữ thì ta sẽ kí hiệu rằng có cặp = 1 và không có cặp là 0.
Vì chúng ta cần toàn bộ họ có đôi có lứa nên chúng ta sẽ cần trả về f((1 << N)-1)
Nói đến đây thôi hi vọng m sẽ hiểu, Fox.
0214191021