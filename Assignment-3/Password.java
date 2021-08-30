public class Password {
	private String password;
	
	public void setPassword(String pw) {
		if(pw==null) {
			throw new IllegalArgumentException("Password cannot be blank");
		}else {
			if(pw.length()<8) {
				throw new IllegalArgumentException("Password too short");
			}
		}
		this.password=pw;
	}
}