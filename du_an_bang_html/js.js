function duansv1(){
	var ten = document.getElementById('ten').value;
	var lop = document.getElementById('lop').value;
	var truong = document.getElementById('truong').value;
	var ngaysinh = document.getElementById('ngaysinh').value;
	var diachi = document.getElementById('diachi').value;
	var sdt = document.getElementById('sdt').value;
	var gioitinh = '';
	if (document.getElementById('nam').checked) {
		gioitinh = document.getElementById('nam').value;
	}
	else if (document.getElementById('nu').checked) {
		gioitinh = document.getElementById('nu').value;
	}
	else if (document.getElementById('khac').checked) {
		gioitinh = document.getElementById('khac').value;
	}
	if(_.isEmpty(ten)){
		document.getElementById('canhbao').innerHTML = 'cảnh báo không đầy đủ thông tin!'
	} else{document.getElementById('canhbao').innerHTML = ''}
	if(_.isEmpty(lop)){
		document.getElementById('canhbao').innerHTML = 'cảnh báo không đầy đủ thông tin!'
	} else{document.getElementById('canhbao').innerHTML = ''}
	if(_.isEmpty(truong)){
		document.getElementById('canhbao').innerHTML = 'cảnh báo không đầy đủ thông tin!'
	} else{document.getElementById('canhbao').innerHTML = ''}
	if(_.isEmpty(diachi)){
		document.getElementById('canhbao').innerHTML = 'cảnh báo không đầy đủ thông tin!'
	} else{document.getElementById('canhbao').innerHTML = ''}
	if(_.isEmpty(ngaysinh)){
		document.getElementById('canhbao').innerHTML = 'cảnh báo không đầy đủ thông tin!'
	} else{document.getElementById('canhbao').innerHTML = ''}
	if(_.isEmpty(sdt)){
		document.getElementById('canhbao').innerHTML = 'cảnh báo không đầy đủ thông tin!'
	} else{document.getElementById('canhbao').innerHTML = ''}
	if(_.isEmpty(gioitinh)){
		document.getElementById('canhbao').innerHTML = 'cảnh báo không đầy đủ thông tin!'
	} else{document.getElementById('canhbao').innerHTML = ''}

	if(ten && lop && truong && ngaysinh && diachi && sdt && gioitinh){
		console.log(ten, lop, truong, diachi, ngaysinh, sdt, gioitinh)
	}

	var sinhvien = localStorage.getItem('sinhvien') ? JSON.parse(localStorage.getItem('sinhvien')) : [];
	sinhvien.push({
		ten: ten,
		lop: lop,
		truong: truong,
		ngaysinh: ngaysinh,
		diachi: diachi,
		sdt: sdt,
		gioitinh: gioitinh,
	});
	localStorage.setItem('sinhvien', JSON.stringify(sinhvien));

	this.duansv2();
}
function duansv2(){
		var sinhvien = localStorage.getItem('sinhvien') ? JSON.parse(localStorage.getItem('sinhvien')) : [];
		if(sinhvien.length === 0) {
			document.getElementById('acc1').style.display = 'none';
			return false;
		}
		document.getElementById('acc1').style.display = 'block';
	var bang = `
	<tr>
		<td >STT</td>
		<td >Họ và tên</td>
		<td >Lớp</td>
		<td >Trường</td>
		<td >Ngày sinh</td>
		<td >Địa chỉ</td>
		<td >Số điện thoại</td>
		<td >giới tính</td>
		<td> hành động</td>
	</tr>
	`;
	sinhvien.forEach((student, index) =>{
		var sinhvienid = index;
		index++;
		bang += `
		<tr>
		<td >${index}</td>
		<td >${student.ten}</td>
		<td >${student.lop}</td>
		<td >${student.truong}</td>
		<td >${student.ngaysinh}</td>
		<td >${student.diachi}</td>
		<td >${student.sdt}</td>
		<td >${student.gioitinh}</td>
		<td>
		<a href='#' onclick='xoasv(${sinhvienid})'>xoa</a>
		</td>
	</tr> 
		`;
	})
	document.getElementById('abc').innerHTML = bang;
	}
function xoasv(id){
	var sinhvien = localStorage.getItem('sinhvien') ? JSON.parse(localStorage.getItem('sinhvien')) : [];
	sinhvien.splice(id, 1);
	localStorage.setItem('sinhvien', JSON.stringify(sinhvien));
	 duansv2()
}