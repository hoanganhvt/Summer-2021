Tóm tắt đề bài: Hãy đếm số lượng số nguyên (Modulo 10^9+7) trong khoảng từ 1 đến k mà tổng các chữ số ở dạng thập phân chia hết cho D

Cách giải:
1) Tạo ra số nguyên '<=' K: 
Phương pháp: Nếu để ý, ta chỉ có thể ghép 1 con số 'Digit' bất kì vào  dãy số N sao cho số sau khi ghép vẫn thỏa đề khi và chỉ khi các con số trước đó phải tồn tại 1 vị trí J sao cho Nj '<' Kj và với mọi j-1 Nj = Kj.
2) Các trạng thái quy hoạch động của bài
Từ phương pháp trên, ta có thể thấy các trạng thái quy hoạch động mà ta cần biết với bài này là vị trí Pos mà t đang xét, Con số mod cho D là bao nhiêu và con số kia đã tồn tại bất kì số Nj nào thỏa Nj '<' Kj hay chưa