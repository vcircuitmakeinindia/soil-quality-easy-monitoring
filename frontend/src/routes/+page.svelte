<script lang="ts">
	import { onMount } from "svelte";
	import Main from "$lib/components/Main.svelte";
	import globals from "$lib/globals";

	let readings = $state([
		{ temperature: 15, humidity: 71, moisture: 461 },
		{ temperature: 19, humidity: 64, moisture: 389 },
		{ temperature: 23, humidity: 38, moisture: 277 }
	]);

	onMount(() => {
		const interval = setInterval(() => {
			// fetch from API
			for (let i = 0; i < readings.length; i++) {
				for (let key of Object.keys(readings[i])) {
					const { min, max } = globals.EXTREMES[globals.OPTIONS.indexOf(key)];
					readings[i][key] = Math.round(Math.random() * (max - min) + min);
				}
			}
		}, 1000);
		return () => clearInterval(interval);
	});
</script>

<Main {readings} />
