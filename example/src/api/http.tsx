import AsyncStorage from '@react-native-async-storage/async-storage';
import type {AxiosRequestConfig} from 'axios';
import RNFS from 'react-native-fs';

export const headers: Readonly<Record<string, string>> = {
	Accept: 'application/json',
	'Content-Type': 'application/json; charset=utf-8',
	'X-Requested-With': 'XMLHttpRequest',
};

export const httpsAgent: Readonly<Record<string, any>> = {
	requestCert: true,
	rejectUnauthorized: false,
	ca:
		'-----BEGIN CERTIFICATE----- MIIGAzCCBOugAwIBAgIRAKFaCm05ZMsRCkGcAw0DBr4wDQYJKoZIhvcNAQELBQAw TDELMAkGA1UEBhMCTFYxDTALBgNVBAcTBFJpZ2ExETAPBgNVBAoTCEdvR2V0U1NM MRswGQYDVQQDExJHb0dldFNTTCBSU0EgRFYgQ0EwHhcNMjIxMjA3MDAwMDAwWhcN MjMxMjA3MjM1OTU5WjAZMRcwFQYDVQQDEw4yMDMuMTUwLjMzLjExODCCASIwDQYJ KoZIhvcNAQEBBQADggEPADCCAQoCggEBANLcibdOvFjYBbjWbrXs+2rt7qEJnd+I FBNLn6TAzofUke9cG9IpVQhE2QtFCJ33pe0B++Tqc3GObCLUjZ5i+ALw7dIboSxc R0cCJRktLwuaLDU1PKOm1cE/OwJcBhDLtOc6UWJ8/sk95+EjF9WOpdM+yBWTacGs tE830Co3hyH7U2dX4rtfY9Zu/wACVqaoRwcuNj5HdtBbRU3JzTTA/jdBMVHGsN8F S2F2gFp2aLyLemExRO5hX9574tMS+Bx05MZK50N7yPA4Ly00bgaYKukGetI7Q4KB OjBFecs1qkrgsQojp8gokLbBcILx6bbUBe9pMoVGhHVCVLNwM/3ENyECAwEAAaOC AxEwggMNMB8GA1UdIwQYMBaAFPn7UMSLZ7tnZP6DIaapzj9VhJOZMB0GA1UdDgQW BBQtJjrg+/5Nvz61uyCy2DZY72F5UDAOBgNVHQ8BAf8EBAMCBaAwDAYDVR0TAQH/ BAIwADAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwSwYDVR0gBEQwQjA2 BgsrBgEEAbIxAQICQDAnMCUGCCsGAQUFBwIBFhlodHRwczovL2Nwcy51c2VydHJ1 c3QuY29tMAgGBmeBDAECATA9BgNVHR8ENjA0MDKgMKAuhixodHRwOi8vY3JsLnVz ZXJ0cnVzdC5jb20vR29HZXRTU0xSU0FEVkNBLmNybDBvBggrBgEFBQcBAQRjMGEw OAYIKwYBBQUHMAKGLGh0dHA6Ly9jcnQudXNlcnRydXN0LmNvbS9Hb0dldFNTTFJT QURWQ0EuY3J0MCUGCCsGAQUFBzABhhlodHRwOi8vb2NzcC51c2VydHJ1c3QuY29t MIIBfgYKKwYBBAHWeQIEAgSCAW4EggFqAWgAdgCt9776fP8QyIudPZwePhhqtGcp Xc+xDCTKhYY069yCigAAAYTtq7kvAAAEAwBHMEUCIBqVgcT7IaASiF5LdGv5GJg9 fH4DXHzpSWbIJZoG15CTAiEAyqEt+5l+54HMPyCLL3EORO+MGEvcOf6JYI5r3MpL IYEAdQC3Pvsk35xNunXyOcW6WPRsXfxCz3qfNcSeHQmBJe20mQAAAYTtq7jGAAAE AwBGMEQCIEWhg40767UUgpi6yyN9qxNYwrw+CTNN3rz5pgX/R6i2AiA0vxegFNf7 7atj8bjlCfXzDK7X9t3XAOgpggAN4IawHgB3AOg+0No+9QY1MudXKLyJa8kD08vR EWvs62nhd31tBr1uAAABhO2ruMcAAAQDAEgwRgIhANQijYjTnTGk7MTfBz3CLNDW YQvWlRL12eVJgbmZHSGmAiEA01e2rs7Ktiapkmh4YzG+61Dk9TC68WrcESPVZkL6 hHYwDwYDVR0RBAgwBocEy5YhdjANBgkqhkiG9w0BAQsFAAOCAQEAAE2JlmXKdKXH sdnih8HxYbd5HXJ33BgWLi9TIFu0DOelsDEID+WL5TtoIy6Mr3NrXzQ299A6v6Kb PR7xz3+Rjs0N+iJ4vAtn22x2AJzXbeIpPEXxqhMgpHR3vZyJL+tVLWNBCwNV24JL NIhIKGRuaBQTvZU/fOi3qfIGjyqO5RE6G62UxX5PYZscGpD6wORzDgbt5H2ajRPQ VuMUKMdHSTH4WDP5B0DJmjzwu4vI6afH683w54ocujnx+uxRVjQKAVlY1UP/ZcSI 5+AWWubjjOCEfHGrwhs/bzIlssG9wDht5R8dLthzBXoQPsXj51Sbyr3iNsRuPfzY cOU6mHwBDg== -----END CERTIFICATE-----',
	cert:
		'-----BEGIN CERTIFICATE----- MIIGAzCCBOugAwIBAgIRAKFaCm05ZMsRCkGcAw0DBr4wDQYJKoZIhvcNAQELBQAw TDELMAkGA1UEBhMCTFYxDTALBgNVBAcTBFJpZ2ExETAPBgNVBAoTCEdvR2V0U1NM MRswGQYDVQQDExJHb0dldFNTTCBSU0EgRFYgQ0EwHhcNMjIxMjA3MDAwMDAwWhcN MjMxMjA3MjM1OTU5WjAZMRcwFQYDVQQDEw4yMDMuMTUwLjMzLjExODCCASIwDQYJ KoZIhvcNAQEBBQADggEPADCCAQoCggEBANLcibdOvFjYBbjWbrXs+2rt7qEJnd+I FBNLn6TAzofUke9cG9IpVQhE2QtFCJ33pe0B++Tqc3GObCLUjZ5i+ALw7dIboSxc R0cCJRktLwuaLDU1PKOm1cE/OwJcBhDLtOc6UWJ8/sk95+EjF9WOpdM+yBWTacGs tE830Co3hyH7U2dX4rtfY9Zu/wACVqaoRwcuNj5HdtBbRU3JzTTA/jdBMVHGsN8F S2F2gFp2aLyLemExRO5hX9574tMS+Bx05MZK50N7yPA4Ly00bgaYKukGetI7Q4KB OjBFecs1qkrgsQojp8gokLbBcILx6bbUBe9pMoVGhHVCVLNwM/3ENyECAwEAAaOC AxEwggMNMB8GA1UdIwQYMBaAFPn7UMSLZ7tnZP6DIaapzj9VhJOZMB0GA1UdDgQW BBQtJjrg+/5Nvz61uyCy2DZY72F5UDAOBgNVHQ8BAf8EBAMCBaAwDAYDVR0TAQH/ BAIwADAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwSwYDVR0gBEQwQjA2 BgsrBgEEAbIxAQICQDAnMCUGCCsGAQUFBwIBFhlodHRwczovL2Nwcy51c2VydHJ1 c3QuY29tMAgGBmeBDAECATA9BgNVHR8ENjA0MDKgMKAuhixodHRwOi8vY3JsLnVz ZXJ0cnVzdC5jb20vR29HZXRTU0xSU0FEVkNBLmNybDBvBggrBgEFBQcBAQRjMGEw OAYIKwYBBQUHMAKGLGh0dHA6Ly9jcnQudXNlcnRydXN0LmNvbS9Hb0dldFNTTFJT QURWQ0EuY3J0MCUGCCsGAQUFBzABhhlodHRwOi8vb2NzcC51c2VydHJ1c3QuY29t MIIBfgYKKwYBBAHWeQIEAgSCAW4EggFqAWgAdgCt9776fP8QyIudPZwePhhqtGcp Xc+xDCTKhYY069yCigAAAYTtq7kvAAAEAwBHMEUCIBqVgcT7IaASiF5LdGv5GJg9 fH4DXHzpSWbIJZoG15CTAiEAyqEt+5l+54HMPyCLL3EORO+MGEvcOf6JYI5r3MpL IYEAdQC3Pvsk35xNunXyOcW6WPRsXfxCz3qfNcSeHQmBJe20mQAAAYTtq7jGAAAE AwBGMEQCIEWhg40767UUgpi6yyN9qxNYwrw+CTNN3rz5pgX/R6i2AiA0vxegFNf7 7atj8bjlCfXzDK7X9t3XAOgpggAN4IawHgB3AOg+0No+9QY1MudXKLyJa8kD08vR EWvs62nhd31tBr1uAAABhO2ruMcAAAQDAEgwRgIhANQijYjTnTGk7MTfBz3CLNDW YQvWlRL12eVJgbmZHSGmAiEA01e2rs7Ktiapkmh4YzG+61Dk9TC68WrcESPVZkL6 hHYwDwYDVR0RBAgwBocEy5YhdjANBgkqhkiG9w0BAQsFAAOCAQEAAE2JlmXKdKXH sdnih8HxYbd5HXJ33BgWLi9TIFu0DOelsDEID+WL5TtoIy6Mr3NrXzQ299A6v6Kb PR7xz3+Rjs0N+iJ4vAtn22x2AJzXbeIpPEXxqhMgpHR3vZyJL+tVLWNBCwNV24JL NIhIKGRuaBQTvZU/fOi3qfIGjyqO5RE6G62UxX5PYZscGpD6wORzDgbt5H2ajRPQ VuMUKMdHSTH4WDP5B0DJmjzwu4vI6afH683w54ocujnx+uxRVjQKAVlY1UP/ZcSI 5+AWWubjjOCEfHGrwhs/bzIlssG9wDht5R8dLthzBXoQPsXj51Sbyr3iNsRuPfzY cOU6mHwBDg== -----END CERTIFICATE-----',
	key:
		'-----BEGIN RSA PRIVATE KEY----- MIIEpQIBAAKCAQEA0tyJt068WNgFuNZutez7au3uoQmd34gUE0ufpMDOh9SR71wb 0ilVCETZC0UInfel7QH75OpzcY5sItSNnmL4AvDt0huhLFxHRwIlGS0vC5osNTU8 o6bVwT87AlwGEMu05zpRYnz+yT3n4SMX1Y6l0z7IFZNpway0TzfQKjeHIftTZ1fi u19j1m7/AAJWpqhHBy42Pkd20FtFTcnNNMD+N0ExUcaw3wVLYXaAWnZovIt6YTFE 7mFf3nvi0xL4HHTkxkrnQ3vI8DgvLTRuBpgq6QZ60jtDgoE6MEV5yzWqSuCxCiOn yCiQtsFwgvHpttQF72kyhUaEdUJUs3Az/cQ3IQIDAQABAoIBAQCeklVKsf54fbQH 5dKKI7aLGnV7S2UbRhV60UM0Pf7TLSu2KrmNWaHlvwjOLdMmIKf6TaSl6R56BlYR 93Cs7NaAN7lRaY/ScW702osVnOIlQoL+XJPGql9TnX597sBs/xSDU1sCyuc8Zb6s k5yH8GeKLkt/1kUQ7hUHAf0c0ndgOGgIwOP+PB99HOf+2PpZQymcjCtEZE+f/erf /3wzFMlSI19Xqk0238C55dP884YMftSNRaI8I0XXcRGJhgBZ39tKdTysqGAbvAKE ULyXlCGaMOFKrDd8ul5TQV4w5z6AHqEfl0Hyflw5yk3mHwNHL0YYVUWuGqb6dj3e yYVOEVhVAoGBAPQG7zdCJkfhCGhERImw1VnvDz2Cw1KXY0/zHl94n59Dbo4ifa7d HyIzt7Uj6iQ1S4l6eYNfKyWDHDx7PKrBcB/ItoQLVLFaE943CPkINR+KNFFQ2H+a 83ypAfair4ZLnjaLkL0FnbeekQIumqb/eM7y63+HAn6EKsgM8BuMg8dPAoGBAN01 CCart0+SqnTo1URxZ056Yd1PGSOnn+qE9FL56UKeN63ifViUXL+QtCwObLZjBTLc 46Z6RrhLLvwU/Tk6dbaIgh0I6RWEwt13Eyidin/MaEY2GOgv0942dTrKStXfju6L OaU3DGZkxqwBDRLoNfhpsZBhvVcgs5wabJsnQX6PAoGAELvA/5sLoPYva2bzBDYa Cza3ZtJmrm0vJDZZqNZOq88l750x3SHQlrnRKRyzW5RD/8NkPbvy63mYIBWbTWJC XAuZaGiWgCrbHevMM7d6XRVPDRxsHCP1+mBkgBMb0iuxR7A+Vpfh/stiyjGD7Vur XxWNTItngmFxxZINjPYPu0UCgYEAxvh9pXMNhtiw1EneExtCRhfU0WDlhumu8R64 Oa6rPw3bnV+9SaDhsDnzpjEvXfrBYVfIuSUBWaHe2EX047YOzaoKBx3NslphgR0r MXxLaNqu7ICadLcYhqdLWR8+oxPcl/rJVi+myq9Y+LxVSy1t5k0Dt5AC5Ez44a/v ArwTsEcCgYEAnaZFBM2yY814ozmY6KUmgDDyfTolL2ZpPp8I/Ky8E1t9RJ4oG+YK xbhtxGHqvuD9RNyehY6fKj+9IDijKisHoBavZunfbdPA0TsqZTXf9FewsUKSzzkB ASVIkCQUOzhtbV+bTeC30MYx2jhgPj/kL1Mh9/qMvHgLJdX3yJtJBXg= -----END RSA PRIVATE KEY-----',
	passphrase: 'Rh6GPwm4',
};

// We can use the following function to inject the JWT token through an interceptor
// We get the `accessToken` from the localStorage that we set when we authenticate
export const injectToken = (config: AxiosRequestConfig | any): AxiosRequestConfig => {
	try {
		const token = AsyncStorage.getItem('token');
		if (token != null) {
			config.headers.Authorization = `Bearer ${token}`;
		}

		return config;
	} catch (error) {
		throw new Error(error as any);
	}
};
