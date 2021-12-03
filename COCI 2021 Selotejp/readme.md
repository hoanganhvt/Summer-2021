COCI 2021 Selotejp
Tóm tắt đề bài: Đối với Mirko, không có hạnh phúc nào lớn hơn việc tìm thấy một cuộn băng dính mới, và ngày hôm nay anh ấy đặc biệt hạnh phúc vì anh ấy còn tìm thêm được cuốn lịch Advent của Slavko.

Cuốn lịch Advent có thể biểu diễn như một bảng hình chữ nhật với n hàng và m cột, mỗi ô vuông chứa một cửa sổ nhỏ, và đằng sau mỗi cửa sổ là một miếng sô cô la. Slavko đã mở một số ô trong số đó, còn những cửa sổ khác vẫn đang đóng.

Mirko quyết định sử dụng cuộn băng dính của anh ấy để dán lại tất cả những cửa sổ đóng. Cuộn băng dính thì dài vô tận, và nó có chiều rộng bằng 1 ô của cuốn lịch. Mirko có thể xé một đoạn băng dính và dùng nó để dán một đoạn liền kề những ô cửa sổ đã đóng theo chiều dọc hoặc chiều ngang. Anh ấy không muốn dán nhiều hơn một lớp băng dính lên bất kì cửa sổ nào, vì anh ấy vẫn muốn giữ tình bạn với Slavko.

Anh ấy đang tự hỏi rằng, anh ấy cần tối thiểu bao nhiêu mẩu băng dính để dán lại hết các cửa sổ đóng trong cuốn lịch.

Phương pháp giải:
Ta có thể dễ dàng nhận thấy, mỗi miếng băng dính sẽ có có 2 trạng thái, hoặc là chúng được đặt dọc, hoặc là chúng được đặt ngang.
Xét cell Aij, ta có thể nhận thấy:
(Từ giờ ta sẽ quy ước đặt dọc là 1, ngang là 0)
1)Nếu Aij = 1 
Khi này ta cần phải xét cell Ai-1j. Nếu 2 cell cùng là 1 ta sẽ không cần tốn thêm miếng băng dính nào còn không ta buộc phải dùng miếng băng mới
2)Nếu Aij = 0
Khi này ta phải xét Aij-1. Nếu 2 cell cùng là 0, ta không cần dùng băng dính mới còn nếu không thì buộc phải dùng cái mới.

Từ đây ta có thể dễ dàng nhận thấy, số lương băng dính mà ta phải sử dụng sẽ phụ thuộc chặt chẽ vào việc ta dán các cell phía trước Aij như thế nào tức Aij-1,Ai-1j-1... Diều đó có nghĩa, ta phải xử lý bài này bằng Phương pháp QUY HOẠCH ĐỘNG TRẠNG THÁI. Vậy các trạng thái của công thức truy hồi sẽ là f(i,j,s) với i,j,s lần lượt là tọa độ của cell và trạng thái.

*Trạng thái cần xét
Như đã nói, số lượng băng dính phụ thuộc chặt chẽ vào các cell phía trước vậy hẳng nhẽ ta sẽ phải xét toàn bộ các cell phía trước rồi đưa vào trạng thái? Hãy nhớ rằng n '<=' 1000 và m '<=' 10 nên số bit của trạng thái sẽ lên đến 10000 bit. Số tối đa là 2^10000, rất lớn. Nên chúng ta cần phải cắt bớt dãy bit này đi.

Với mỗi cell, ta chỉ cần quan tâm đến bit đại diện cho Aij-1 và Ai-1j nên có thể cắt bớt đi và chỉ xét m bit cuối kể từ bit Aij. 