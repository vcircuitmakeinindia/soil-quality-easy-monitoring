import globals from "./globals";

const ENDPOINT = "http://192.168.XX.XX:XXXX/sqm";

export async function getData() {
	return genMockData(); // comment to fetch from api
	const resp = await fetch(ENDPOINT);
	if (resp.status !== 200) return genMockData();
	try {
		return (await resp.json()).data;
	} catch {
		return genMockData();
	}
}

export function genMockData(len: number = 3) {
	const readings = Array(len);
	for (let i = 0; i < readings.length; i++) {
		readings[i] = { humidity: 0, temperature: 0, moisture: 0 };
		for (let key of Object.keys(readings[i])) {
			const { min, max } = globals.EXTREMES[globals.OPTIONS.indexOf(key)];
			readings[i][key] = Math.round(Math.random() * (max - min) + min);
		}
		readings[i].cluster_no = i + 1;
	}
	return readings;
}

export default {
	getData
};
